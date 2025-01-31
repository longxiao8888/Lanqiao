#include <bits/stdc++.h>
using namespace std;
// bfs路径打印
// https://blog.csdn.net/ryo_218/article/details/88830082?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_paycolumn_v3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_paycolumn_v3&utm_relevant_index=1
int m, n; //长，高
struct node
{
    int x;
    int y;
    string path;
};
char maze[100][100];
bool visit[100][100];
int dirx[4] = {1, 0, 0, -1}; // D<L<R<U
int diry[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};
bool judge(int x, int y, int startx, int starty)
{
    if (x == n && y == m)
        return true;
    else
        return false;
}
void bfs(int startx, int starty)
{
    queue<node> q;
    visit[startx][starty] = 1;
    node p;
    p.x = startx, p.y = starty;
    q.push(p);
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        string way = q.front().path;
        q.pop();
        if (judge(x, y, startx, starty))
        {
            cout << way;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int rempx = x + dirx[i];
            int rempy = y + diry[i];
            string rempway = way + dir[i];
            if (maze[rempx][rempy] == '0' && visit[rempx][rempy] == 0 && rempx <= n && rempx > 0 && rempy <= m && rempy > 0)
            {
                // cout<<"1 ";
                //  cout<<rempway<<endl;
                visit[rempx][rempy] = 1;
                node remp;
                remp.x = rempx, remp.y = rempy, remp.path = rempway;
                // cout << rempway << endl;
                q.push(remp);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        string remp;
        cin >> remp;
        for (int j = 1; j <= m; j++)
        {
            maze[i][j] = remp[j - 1];
        }
    }
    bfs(1, 1);
    return 0;
}
/* 样例
50 30
01010101001011001001010110010110100100001000101010
00001000100000101010010000100000001001100110100101
01111011010010001000001101001011100011000000010000
01000000001010100011010000101000001010101011001011
00011111000000101000010010100010100000101100000000
11001000110101000010101100011010011010101011110111
00011011010101001001001010000001000101001110000000
10100000101000100110101010111110011000010000111010
00111000001010100001100010000001000101001100001001
11000110100001110010001001010101010101010001101000
00010000100100000101001010101110100010101010000101
11100100101001001000010000010101010100100100010100
00000010000000101011001111010001100000101010100011
10101010011100001000011000010110011110110100001000
10101010100001101010100101000010100000111011101001
10000000101100010000101100101101001011100000000100
10101001000000010100100001000100000100011110101001
00101001010101101001010100011010101101110000110101
11001010000100001100000010100101000001000111000010
00001000110000110101101000000100101001001000011101
10100101000101000000001110110010110101101010100001
00101000010000110101010000100010001001000100010101
10100001000110010001000010101001010101011111010010
00000100101000000110010100101001000001000000000010
11010000001001110111001001000011101001011011101000
00000110100010001000100000001000011101000000110011
10101000101000100010001111100010101001010000001000
10000010100101001010110000000100101010001011101000
00111100001000010000000110111000000001000000001011
10000001100111010111010001000110111010101101111000
*/