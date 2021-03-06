#include <stdio.h>
int main(void)
{
	float matrix[4][2]={{1,4},{2,5},{5,1},{4,2}};
	float result[4]={19,26,19,20};
	float theta[2]={2,5};
	float loss = 10.0;
	for(int i =0 ;i<100&&loss>0.001;++i)
	{
		float error_sum=0.0;
		int j=i%4;
		{
			float h = 0.0;
			for(int k=0;k<2;++k)
			{
				h += matrix[j][k]*theta[k];

			}
			error_sum = result[j]-h;
			for(int k=0;k<2;++k)
			{
				theta[k] = theta[k]+0.01*(error_sum)*matrix[j][k];
			}
		}
		printf("j = %d\n", j);	
		printf("%f,%f\n",theta[0],theta[1]);
		float loss = 0.0;
		for(int j = 0;j<4;++j)
		{
			float sum=0.0;
			for(int k = 0;k<2;++k)
			{

				sum += matrix[j][k]*theta[k];
			}
			loss += (sum-result[j])*(sum-result[j]);
		}
		printf("%f\n",loss);
	}
	return 0;
}