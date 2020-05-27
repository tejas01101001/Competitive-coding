const int n = 8;
int sx, sy;
int a[64];

static int cx[n] = {1, 1, 2, 2, -1, -1, -2, -2};
static int cy[n] = {2, -2, 1, -1, 2, -2, 1, -1};

bool limits(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

bool isempty(int x, int y)
{
    return (limits(x, y) && a[x * n + y] < 0);
}

bool neigh(int x, int y, int xx, int yy)
{
    forz(i, n)
    {
        if ((x + cx[i] == xx) && (y + cy[i] == yy))
            return true;
    }
    return false;
}

void print()
{
    forz(i, n)
    {
        forz(j, n) p0(a[i * n + j]);
        cout << endl;
    }
}

int getdeg(int x, int y)
{
    int cnt = 0;
    forz(i, n)
    {
        if (isempty(x + cx[i], y + cy[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

pii nextmov(int x, int y)
{
    int min_id = -1, min_deg = n + 1;
    int c, nx, ny;

    int start = rand() % n;
    forz(i, n)
    {
        int ci = (start + i) % n;
        nx = x + cx[ci];
        ny = y + cy[ci];

        if (isempty(nx, ny) && (c = getdeg(nx, ny)) < min_deg)
        {
            min_id = ci;
            min_deg = c;
        }
    }
    if (min_id == -1)
        return {-1, -1};

    nx = x + cx[min_id];
    ny = y + cy[min_id];

    a[nx * n + ny] = a[x * n + y] + 1;

    return {nx, ny};
}

bool knight()
{
    memset(a, -1, sizeof(a));
    int x = sx;
    int y = sy;
    a[x * n + y] = 1;

    forz(i, 63)
    {
        debug(x,y);
        pii p = nextmov(x, y);
        if (p.F == -1 && p.S==-1)
            return false;
        else
        {
            x = p.F;
            y = p.S;
        }
    }

    if (!neigh(x, y, sx, sy))
        return false;

    print();
    return true;
}

int main()
{
    kira;
    cin >> sy >> sx;
    sx--;
    sy--;

    srand(time(0));
    while (!knight())
    
    return 0;
}