#include <stdio.h>

const int maxdata = 24; // 円盤の最大枚数は, 色の最大種類:4種類 * 1種類の色の最大枚数:6枚 = 24枚

typedef struct node // 円盤のデータを構造体として保存する.
{
  int _x;            // 円盤のx座標.
  int _y;            // 円盤のy座標.
  int _r;            // 円盤の半径.
  int _c;            // 円盤の色.
  int _numOfOverlap; // 重なっている円盤の枚数(負の数の時は既に取り除かれた円盤であることを表す).
  int _overlap[24];  // 上に重なっている円盤の番号を記録するための配列.
  int _overlaped;    // 下に重なっている円盤の枚数を記録するための変数.
} DATA;

int overlapCheck(const int x1, const int y1, const int r1, const int x2, const int y2, const int r2) // 重なっているか否かを判定する関数.
{
  return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 + r2) * (r1 + r2)); // 重なっている時は1, 重なっていない時は0を返す.
}

void removeDisk(const int i, const int j, DATA data[maxdata]) // i枚目の円盤とj枚目の円盤を取り除く関数.
{
  int k;

  for (k = i + 1; k < j; k++)
  {
    if (data[k]._numOfOverlap == -1) // k番目の円盤が存在しない場合はスキップ.
    {
      continue;
    }

    if (data[k]._overlap[i] == 1) // k番目の円盤の上にi番目の円盤が重なっていた場合には, i番目の円盤の情報をk番目の円盤から取り除く.
    {
      data[k]._numOfOverlap -= 1;
      data[k]._overlap[i] -= 1;
    }
  }
  data[i]._numOfOverlap = -1; // i番目の円盤を取り除く.
  data[j]._numOfOverlap = -1; // j番目の円盤を取り除く.
}

void calcOverlap(const int dataLocation, DATA data[maxdata]) // dataLocation番目の円盤がどの円盤と重なっているかを確かめ, 記録する関数.
{
  int i;

  for (i = 0; i < dataLocation; i++)
  {
    if (overlapCheck(data[i]._x, data[i]._y, data[i]._r, data[dataLocation]._x, data[dataLocation]._y, data[dataLocation]._r)) // i番目とdataLocation番目の円盤が重なっていた場合には,
    {
      data[dataLocation]._numOfOverlap += 1; // 重なっている円盤の枚数を1枚増やし,
      data[dataLocation]._overlap[i] = 1;    // i番目の円盤が重なっていることをoverlap配列に記録する.
      data[i]._overlaped += 1;               // i番目の円盤の下に重なっていることを記録する.
    }
  }
}

void search(int *first, int *second, const int n, DATA data[maxdata]) // 下に最も重なっている円盤の番号を検出し, その円盤と同じ色で最も下に重なっている円盤の枚数が多い円盤の番号を探す関数.
{
  int i, max = -1;

  for (i = 0; i < n; i++)
  {
    if (data[i]._numOfOverlap != 0) // i番目の円盤が存在しない場合にはスキップ.
    {
      continue;
    }

    if (data[i]._overlaped > max)
    {
      max = data[i]._overlaped;
      *first = i;
    }
  }

  max = -1;
  for (i = 0; i < n; i++)
  {
    if (data[i]._numOfOverlap != 0) // i番目の円盤が存在しない場合にはスキップ.
    {
      continue;
    }

    if (i != *first && data[i]._c == data[*first]._c && data[i]._overlaped > max)
    {
      max = data[i]._overlaped;
      *second = i;
    }
  }
}

int check(const int n, DATA data[maxdata]) // 重なっていない円盤を見つけて, 取り除いた円盤の数を計算し返す関数.
{
  int ans = 0, first = -1, second = -1;

  while (1)
  {
    search(&first, &second, n, data);
    if (data[first]._numOfOverlap < 0 || data[second]._numOfOverlap < 0)
    {
      break;
    }

    first < second
        ? removeDisk(first, second, data)
        : removeDisk(second, first, data);
    ans += 2;
  }

  return ans; // 計算して答えを返す.
}

int inputData(const int n, DATA data[maxdata]) // data配列に円盤のデータを入力し, 取り除ける円盤の最大枚数を返す関数.
{
  int i, j;

  for (i = 0; i < n; i++)
  {
    data[i]._numOfOverlap = 0; // 重なっている円盤の枚数の初期値は0.
    for (j = 0; j < maxdata; j++)
    {
      data[i]._overlap[j] = 0; // overlap配列の全要素を0で初期化する.
    }
    data[i]._overlaped = 0; // 下に重なっている円盤の枚数の初期値は0.

    scanf("%d %d %d %d", &(data[i]._x), &(data[i]._y), &(data[i]._r), &(data[i]._c)); // i番目の円盤のx, y, r, cを標準入力から受け取る.
    calcOverlap(i, data);                                                             // i番目の円盤の上に重なっている円盤の枚数を計算する.
  }

  return check(n, data); // 取り除ける円盤の最大枚数を計算し, 返す.
}

int main(void)
{
  int n;
  DATA data[maxdata]; // data構造体配列(要素数maxdata)に円盤の各種情報を格納する.

  while (1)
  {
    scanf("%d", &n); // nを標準入力から受け取る.
    if (n == 0)      // nが0の時は終了する.
    {
      break;
    }

    printf("%d\n", inputData(n, data)); // 標準入力からデータを受け取り, 取り除ける最小枚数を計算し, その答えを標準出力する.
  }

  return 0;
}
