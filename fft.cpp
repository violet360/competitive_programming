#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846
vector<complex<double> > fft(vector<complex<double> > a)
{
	//for(int i = 0;i<a.size();i++)cout<<a[i]<<“ “;cout<<endl;
	int n = (int)a.size();
	if(n <= 1)
	return a;
	vector<complex<double> > a0(n/2), a1(n/2);
	for(int i = 0;i<n/2;i++)
	{
		a0[i] = a[2*i];
		a1[i] = a[2*i + 1];
		//cout<<n<<“ “<<a0[i]<<“ “<<a1[i]<<endl;
	}
	a0 = fft(a0);
	a1 = fft(a1);
	double ang = 2*PI/n;
	complex<double> w(1) , wn(cos(ang),sin(ang));
	for(int i = 0;i<n/2;i++)
	{
		a[i] = a0[i] + w*a1[i];
		a[i + n/2] = a0[i] - w*a1[i];
		w *= wn;
		//cout<<a[i]<<“ “<<a[i+n/2]<<endl;
	}
	return a;
}

vector<complex<double> > inv_fft(vector<complex<double>>y)
{
	int n = y.size();
	if(n <= 1)
		return y;
	vector<complex<double> > y0(n/2), y1(n/2);
	for(int i = 0;i<n/2;i++)
	{
		y0[i] = y[2*i];
		y1[i] = y[2*i + 1];
	}
	y0 = inv_fft(y0);
	y1 = inv_fft(y1);
	double ang = 2 * PI/n * -1;
	complex<double> w(1), wn(cos(ang), sin(ang));
	for(int i = 0;i<n/2;i++)
	{
		y[i] = y0[i] + w*y1[i];
		y[i + n/2] = y0[i] - w*y1[i];
		y[i] /= 2;
		y[i + n/2] /= 2;
		w *= wn;
	}
	return y;
}



void multiply(vector<int> a, vector<int> b)
{
	vector<complex<double> > fa(a.begin(),a.end()), fb(b.begin(),b.end());
	int n = 1;
	while(n < max(a.size(),b.size()))
		n <<= 1;
	n <<= 1;
	// cout<<n<<endl;
	fa.resize(n);
	fb.resize(n);
	fa = fft(fa);
	fb = fft(fb);
	for(int i = 0;i<n;i++)
	{
		fa[i] = fa[i] * fb[i];
		// cout<<fa[i]<<endl;
	}
	fa = inv_fft(fa);
	vector<int> res(n);
	for(int i = 0;i<n;i++)
	{
		res[i] = int(fa[i].real()+0.5);
		cout<<res[i]<<" ";
	}
	
	return;
}


int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m, n, inp;
		cin>>n>>m;
		vector<int> f1,f2;
		
		for(int i = 0;i<n;i++)
		{
			cin>>inp;
			f1.push_back(inp);
		}
		for(int i = 0;i<m;i++)
		{
			cin>>inp;
			f2.push_back(inp);
		}
		multiply(f1,f2);
	}
	return 0;
}