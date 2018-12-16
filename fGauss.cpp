#include <iostream>
using namespace std;

void show(float matrix[][100],int incognitas, int ecuaciones)
{
	for(int ecuacion_ = 0; ecuacion_<ecuaciones; ecuacion_++)
	{
		for(int incognita_ = 0; incognita_<incognitas; incognita_++)
		{
			cout<<matrix[incognita_][ecuacion_]<<"\t";
		}
	cout<<endl;
	}

}


int stepper(int ecuation)
{
	int step = 0;
	for(int st = 0;st<ecuation;st++){step = step+st;}
	return step;
}

void calculator(float matrix[][100],int un,int ecuation)
{
	int p = stepper(ecuation);
	cout<<"the solution of the system will be found in "<<p<<" steps"<<endl;
	for(int i = 0; i<un-2; i++)
	{
		for(int k = i+1; k<ecuation; k++)
		{

			float prod_1 = matrix[i][k];
			float prod_0 = matrix[i][i];
			cout<<endl<<"step:"<<prod_0<<"E_"<<k+1<<"-"<<prod_1<<"E_"<<i+1<<endl;
			for(int x = 0; x<un; x++)
			{

				matrix[x][k] = (matrix[x][k]*prod_0)-(prod_1*matrix[x][i]);
			}
			show(matrix,un,ecuation);
			cout<<endl;
		}
	}
	cout<<"the the matrix is now a triangular one :)"<<endl;
	show(matrix,un,ecuation);

}


int main()
{
int ec,inc;
cout<<"Write the dimensions of the matrix: ";
cin>>ec>>inc;
float mat[inc][100];
cout<<"Now, write the coeficients of each row one by one: "<<endl;
for(int sum = 0; sum<5; sum++)
{
	for (int z = 0; z<inc; z++)
	{
		if(sum<ec){cin>>mat[z][sum];}
		else{mat[z][sum] = 0;}
	}

}

show(mat,inc,ec);
calculator(mat,inc,ec);
///if(ec+1==inc){calculator(mat,inc,ec);}
return 0;
}

