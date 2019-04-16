#include <stdio.h>
#include <string.h>

#define COLORS 6
#define MAXSIZE 64
#define MAXPHASE 5

void debugPrint(const int h, const int w, char panels[MAXSIZE + 1]) // 4debug
{
  int i;

  printf("--debug print--\n"); // 4debug

  for (i = 0; i < h * w; i++)
  {
    printf("%c", panels[i]);
    if (i % w == w - 1)
      printf("\n");
  }

  printf("\n");
}
int changeColor(const int h, const int w, const char color, char panels[MAXSIZE + 1], const int index, int ans)
{
  if ((index + 1) % w != 0 && panels[index + 1] == panels[index])
  {
    changeColor(h, w, color, panels, index + 1, ans);
  }
  if (index / h + 1 < w && panels[index + w] == panels[index])
  {
    changeColor(h, w, color, panels, index + w, ans);
  }

  panels[index] = color;

  return ++ans;
}

int calcMaxPanel(const int h, const int w, const char c, char panels[MAXSIZE + 1], const int phase, int ans) // 残っているトカゲの数を計算して返す関数.
{
  int i, cnd;
  char p[6][MAXSIZE + 1];

  printf("phase:%d, ans:%d\n", phase, ans); // 4debug
  debugPrint(h, w, panels);                 // 4debug

  switch (phase)
  {
  case 0:
  {
    for (i = 0; i < 2; i++)
    {
      strcpy(p[i], panels);
    }

    ans = changeColor(h, w, panels[1], p[0], 0, 0);
    cnd = changeColor(h, w, panels[w], p[1], 0, 0);
    ans = calcMaxPanel(h, w, c, p[1], phase + 1, ans);
    cnd = calcMaxPanel(h, w, c, p[0], phase + 1, ans);
    if (cnd > ans)
    {
      ans = cnd;
    }

    break;
  }
  case MAXPHASE - 1:
  {
    ans = changeColor(h, w, c, panels, 0, 0);
    break;
  }
  default:
  {
    for (i = 0; i < COLORS; i++)
    {
      strcpy(p[i], panels);
      cnd = changeColor(h, w, i + 1 + ('0' - 0), p[i], 0, 0);
      if (cnd > ans)
      {
        ans = cnd;
      }
      ans = calcMaxPanel(h, w, c, p[i], phase + 1, ans);
    }
    break;
  }
  }

  return ans;
}

int main(void)
{
  int h, w, i, buf;
  char c, panels[MAXSIZE + 1]; // Tの最大文字数は100文字.

  while (1)
  {
    scanf("%d %d %d", &h, &w, &buf);
    if (h == 0 && w == 0 && buf == 0)
    {
      break;
    }
    c = buf + ('0' - 0);

    for (i = 0; i < h * w; i++)
    {
      scanf("%d", &buf);
      panels[i] = buf + ('0' - 0);
    }

    printf("%d\n", calcMaxPanel(h, w, c, panels, 0, 0)); // 残った個体数を計算し, 答えを標準出力する.
  }

  return 0;
}
