## 概要

時間を測る。 `std::chrono` を使用している。

- `Timer()` : 時間計測をはじめる。
- `void restart()` : タイマーをリセットしてリスタートする。
- `double elapsed()` : タイマーの現在の時間を返す。単位はミリ秒。
- `double get_start_time()` : 最後にタイマーをリセットした時刻を返す。
- `double get_now_time()` : 現在の時刻を返す。
