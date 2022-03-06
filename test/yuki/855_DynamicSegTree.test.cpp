#define PROBLEM "https://yukicoder.me/problems/no/855"
#include "../../other/template.hpp"
#include "../../data-struct/segment/DynamicSegmentTree.hpp"
using namespace std;
int main() {
    ll H, W, N; cin >> H >> W >> N;
    DynamicSegmentTree<Monoid::Max<ll>> segl(H + 2), segu(W + 2);
    DynamicSegmentTree<Monoid::Min<ll>> segr(H + 2), segd(W + 2);
    map<ll, ll> mpl, mpr, mpu, mpd;
    rep (N) {
        ll x, y, l; cin >> x >> y >> l;
        bool flg = false;
        if (y == 0 || y == H + 1) {
            swap(H, W);
            swap(x, y);
            swap(segl, segu); swap(segr, segd);
            swap(mpl, mpu); swap(mpr, mpd);
            flg = true;
        }
        if (x == 0) {
            if (mpl.count(y)) {
                l += mpl[y];
                mpl.erase(y);
                segl.reset(y);
            }
            ll nx = min(l, W);
            ll idx = infinity<ll>::max, kd = -1;
            if (l >= W + 1) {
                idx = W + 1; kd = 3;
            }
            if (mpr.count(y) && mpr[y] <= nx) {
                if (chmin(idx, mpr[y])) kd = 0;
            }
            if (segu.prod(0, nx + 1) >= y) {
                if (chmin(idx, segu.max_right(0, [&](ll a) { return a < y; }))) kd = 1;
            }
            if (segd.prod(0, nx + 1) <= y) {
                if (chmin(idx, segd.max_right(0, [&](ll a) { return a > y; }))) kd = 2;
            }
            if (kd == 0) {
                mpr.erase(y);
                segr.reset(y);
            }
            else if (kd == 1) {
                mpu.erase(idx);
                segu.reset(idx);
            }
            else if (kd == 2) {
                mpd.erase(idx);
                segd.reset(idx);
            }
            else if (kd == -1) {
                mpl[y] = nx;
                segl.set(y, nx);
            }
        }
        if (x == W + 1) {
            if (mpr.count(y)) {
                l += W + 1 - mpr[y];
                mpr.erase(y);
                segr.reset(y);
            }
            ll nx = max(W - l + 1, 0ll);
            ll idx = infinity<ll>::min, kd = -1;
            if (l >= W + 1) {
                idx = 0; kd = 3;
            }
            if (mpl.count(y) && nx <= mpl[y]) {
                if (chmax(idx, mpl[y])) kd = 0;
            }
            if (segu.prod(nx, W + 2) >= y) {
                if (chmax(idx, segu.min_left(W + 2, [&](ll a) { return a < y; }) - 1)) kd = 1;
            }
            if (segd.prod(nx, W + 2) <= y) {
                if (chmax(idx, segd.min_left(W + 2, [&](ll a) { return a > y; }) - 1)) kd = 2;
            }
            if (kd == 0) {
                mpl.erase(y);
                segl.reset(y);
            }
            else if (kd == 1) {
                mpu.erase(idx);
                segu.reset(idx);
            }
            else if (kd == 2) {
                mpd.erase(idx);
                segd.reset(idx);
            }
            else if (kd == -1) {
                mpr[y] = nx;
                segr.set(y, nx);
            }
        }
        if (flg) {
            swap(H, W);
            swap(x, y);
            swap(segl, segu); swap(segr, segd);
            swap(mpl, mpu); swap(mpr, mpd);
        }
    }
    ll ans = 0;
    each_const (p : mpl) ans += p.second;
    each_const (p : mpr) ans += W + 1 - p.second;
    each_const (p : mpu) ans += p.second;
    each_const (p : mpd) ans += H + 1 - p.second;
    cout << ans << endl;
}
