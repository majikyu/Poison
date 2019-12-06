## ポアソン分布
このプログラムは，ポアソン分布で一定時間に発生する事象の間隔を出力するものです．用途に応じてコードを書き換えてください．

コード内のマクロについて，次章に記します．
## マクロ
コードのトップに記されているマクロの意味を説明します．
`MAX_WAIT`

事象間隔の最大値です．この時間以上，間隔は空かなくなります．

`EXEC_TIME`

何秒間の事象発生を出力するか定めます．

`LMD`
1分あたり，平均何回起こる事象であるか定めます．

`ACCURACY`
間隔時間の精度です．大きいほど精度が高くなりますが，計算量が大きくなります．
---

デフォルトでは，1分あたり平均200回起こる事象が，1分間に発生する間隔が出力されます．
