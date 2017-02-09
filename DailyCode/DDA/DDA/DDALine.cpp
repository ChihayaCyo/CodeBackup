#include<stdlib.h>
#include<math.h> 

using namespace std;

void DDALine(int x0, int y0, int x1, int y1)
{
	int x, y, k;
	k = (y1 - y0) / (x1 - x0);
	y = y0;
	for (x = x0; x<x1; x++)
	{
		y = y + k;
		setPixel(x, (int)(y + 0.5));
	}

}

int main() {
	cout << "Please input x0,y0 x1,y1 color:" << endl;	//输入的都是正整数 
	cin >> x0 >> y0 >> x1 >> y1;
	DDAline(x0, y0, x1, y1)
	return 0;
}

