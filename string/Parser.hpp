#pragma once

#include "../other/template.hpp"

template<class Res>
class Parser {
public:
    class ParseError : public std::exception {
    private:
        std::string message;

    public:
        ParseError(const std::string& message) : message(message) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
    class State;

private:
    using Iter = typename std::string::const_iterator;
    using ParserFunc = std::function<Res(State&)>;
    using ParserFuncs = std::vector<ParserFunc>;
    using ParserName = std::string;
    using ParserNames = std::vector<ParserName>;

    ParserFuncs parsers;
    ParserNames names;

public:
    class State {
    private:
        ParserFuncs& parsers;
        ParserNames& names;
        Iter& iter;

    public:
        State(ParserFuncs& parsers, ParserNames& names, Iter& iter) : parsers(parsers), names(names), iter(iter) {}
        char operator*() const {
            return *iter;
        }
        void operator++() {
            ++iter;
        }
        void operator--() {
            --iter;
        }
        void consume(char expected) {
            if (*iter == '\0') throw ParseError("expected '" + std::string(1, expected) + "', but got EOF");
            if (*iter != expected) throw ParseError("expected '" + std::string(1, expected) + "', but got '" + std::string(1, *iter) + "'");
            iter++;
        }
        void consume(const std::string& expected) {
            for (char c : expected) consume(c);
        }
        Res call(const ParserName& name) {
            rep (i, names.size()) {
                if (names[i] == name) return parsers[i](*this);
            }
            throw ParseError("unknown parser name: " + name);
        }
        void error(const std::string& message) {
            throw ParseError(message);
        }
    };

    Parser() {}
    void add_parser(const ParserName& name, const ParserFunc& parser) {
        names.push_back(name);
        parsers.push_back(parser);
    }
    std::function<int()> f;
    Res parse(const std::string& s, int expr = 0) {
        Iter iter = s.begin();
        State state(parsers, names, iter);
        Res res = parsers[expr](state);
        if (iter != s.end()) throw ParseError("unexpected character: '" + std::string(1, *iter) + "'");
        return res;
    }
};

template<class Res>
class OperatorParser {
private:
    using P = Parser<Res>;

public:
    using State = typename P::State;

private:
    using OperatorFunc = std::function<Res(Res, Res)>;
    using FunctionFunc = std::function<Res(Res)>;
    using TermFunc = std::function<Res(typename P::State&)>;

    std::vector<std::vector<OperatorFunc>> ops;
    std::vector<std::vector<std::string>> op_names;
    std::vector<FunctionFunc> funcs;
    std::vector<std::string> func_names;
    TermFunc term;

    static Res int_term(typename P::State& state) {
        bool neg = false;
        if (*state == '-') {
            neg = true;
            ++state;
        }
        int res = 0;
        while ('0' <= *state && *state <= '9') {
            res = res * 10 + (*state - '0');
            ++state;
        }
        if (neg) res = -res;
        return res;
    }

public:
    OperatorParser() {}
    OperatorParser(int n) : ops(n), op_names(n), term(int_term) {}
    OperatorParser(int n, const TermFunc& term) : ops(n), op_names(n), term(term) {}
    void add_operator(int i, const std::string& name, const OperatorFunc& parser) {
        ops[i].push_back(parser);
        op_names[i].push_back(name);
    }
    void add_function(const std::string& name, const FunctionFunc& parser) {
        funcs.push_back(parser);
        func_names.push_back(name);
    }
    Res parse(const std::string& s) {
        P parser;
        rrep (i, ops.size()) {
            parser.add_parser("op" + std::to_string(i + 1), [this, i](typename P::State& state) -> Res {
                Res res = state.call("op" + std::to_string(i));
                while (true) {
                    bool found = false;
                    rep (j, ops[i].size()) {
                        found = true;
                        rep (k, op_names[i][j].size()) {
                            if (*state == op_names[i][j][k]) ++state;
                            else {
                                found = false;
                                rep (k) --state;
                                break;
                            }
                        }
                        if (found) {
                            res = ops[i][j](res, state.call("op" + std::to_string(i)));
                            break;
                        }
                    }
                    if (!found) break;
                }
                return res;
            });
        }
        parser.add_parser("op0", [this](typename P::State& state) -> Res {
            if (*state == '(') {
                ++state;
                Res res = state.call("op" + std::to_string(ops.size()));
                state.consume(')');
                return res;
            }
            rep (i, funcs.size()) {
                bool found = true;
                rep (j, func_names[i].size()) {
                    if (*state == func_names[i][j]) ++state;
                    else {
                        found = false;
                        rep (j) --state;
                        break;
                    }
                }
                if (found) {
                    state.consume('(');
                    Res res = funcs[i](state.call("op" + std::to_string(ops.size())));
                    state.consume(')');
                    return res;
                }
            }
            return term(state);
        });
        return parser.parse(s, 0);
    }
};
