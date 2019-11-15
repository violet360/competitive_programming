#include <iostream>
#include <cassert>
 
using namespace std;
 
const int MAX = 15;
const int MODULO = 1000000000;
 
struct matrix{
    int rowSize = MAX - 1;
    int columnSize = MAX - 1;
    int data[MAX][MAX];
    matrix () 
    {
        for (int i = 1; i <= rowSize; i ++) 
        {
            for (int j = 1; j <= columnSize; j ++) 
            {
                data[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix other) const{
        assert(columnSize == other.rowSize);
        matrix result = matrix();
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= other.columnSize; j ++) {
                for (int k = 1; k <= columnSize; k ++) {
                    result.data[i][j] = (result.data[i][j] + 1LL * data[i][k] * other.data[k][j] % MODULO) % MODULO;
                }
            }
        }
        result.rowSize = rowSize;
        result.columnSize = other.columnSize;
        return result;
    }
    matrix power(int e)
    {
        if (e == 1) {
            return *this;
        }
        if (e & 1) {
            return (*this) * power(e - 1);
        }
        matrix half = power(e >> 1);
        return half * half;
    }
};
 
int b[MAX], c[MAX];
 
int main()
{
	int Test;
	cin>>Test;
	while(Test--)
	{
		int k;
		cin>>k;
		for(int x=1; x<=k; x++)
		{
			cin>>b[x];
		}
 
		for(int x=1; x<=k; x++)
		{
			cin>>c[x];
		}
 
		int n;
		cin>>n;
 
		if(n<=k)
		{
			cout<<b[n]<<endl;
			continue;
		}
 
		else
		{
			matrix T, I;
 
			T.rowSize = k;
        	T.columnSize = k;
 
			for(int x=2; x<=k; x++)
			{
				T.data[x-1][x] = 1;
			}
 
			for(int x=1; x<=k; x++)
			{
				T.data[k][x] = c[k-x+1];
			}
 
			I.rowSize = k;
        	I.columnSize = 1;
 
        	for(int y=1; y<=k; y++)
        	{
        		I.data[y][1] = b[y];
        	}
 
        	matrix res = T.power(n-k) * I;
 
        	cout<<res.data[k][1]<<endl;
		}
	}
 
	return 0;
}
