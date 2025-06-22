#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define mod 1000000007
#define ll long long

bool sign(int);
double f(double);

/* -------------------------- Functions available --------------------------- */
void fixedPointMethod();
void secantMethod(int,const int);
void regularfalsi();
void GaussElimination(int, bool);
void printmatrix(vector<vector<float>>);
void GaussJacobi(int);
void dividendDifferenceTable(int);

double f(double x)
{
        double res = (sin(x) + 1) / 3;               // define your function here
        return res;
}

/* -------------------------- Main Function --------------------------- */
int main()
{
        system("clear");

        int iterations = 15;   // define number of iterations here
        const int places = 6; // define number of places to be entered
        //secantMethod(iterations,places);

        // fixedPointMethod();

        //GaussElimination(-1, true);

        //GaussJacobi(-1);

        dividendDifferenceTable(8);
        return 0;
}


/* --------------------------  Function Definations --------------------------- */

bool sign(int x)
{
        return x > 0;
}

void fixedPointMethod()
{
        double x = 0;
        for (int i = 0; i < 1000; i++)
                if (sign(f(i)) != sign(f(i + 1)))
                {
                        x = i;
                        break;
                }
        int iterations = 9;	   // define number of iterations here
        const int places = 10; // define number of places to be entered
        x = (2 * x + 1) / 2;
        for (int i = 0; i < iterations; i++)
        {
                x = f(x);
                cout << "\tfor " << i << " th it is: " << fixed << setprecision(places) << x << "\n";
        }
}

void secantMethod(int iterations=15,int places=6)
{
        cout<<"Performing Secant Method...\n\n";
        double x = 0, y = 0;
        for (int i = 0; i < 1000; i++)
                if (sign(f(i)) != sign(f(i + 1)))
                {
                        x = i;
                        break;
                }
        y = x + 1;
        for (int i = 0; i < iterations; i++)
        {
                cout << "i = " << i << "\t\tx is: " << fixed << setprecision(places) << x << " \t y is : " << y << "\n";
                x = f(x);
        }
}

void regularfalsi()
{
}

void GaussElimination(int n, bool wannaprint = false)
{
        int i, j, k;
        if (n == -1)
        {
                cout << "\nEnter the no. of equations: ";
                cin >> n;
        }
        /* if no of equations are n then size of augmented matrix will be n*n+1. So here we are declaring 2d array 'mat' of size n+n+1 */
        vector<vector<float>> mat;

        /* for n equations there will be n unknowns which will be stored in array 'res' */
        float res[n];

        cout << "\nEnter the elements of the augmented matrix (Total " << n << " x " << (n + 1) << " elements): \n";
        for (i = 0; i < n; i++)
        {
                vector<float> temp;
                for (j = 0; j < n + 1; j++)
                {
                        int x;
                        cin >> x;
                        temp.push_back(x);
                }
                mat.push_back(temp);
        }

        for (i = 0; i < n; i++)
        {
                for (j = i + 1; j < n; j++)
                {
                        if (abs(mat[i][i]) < abs(mat[j][i]))
                        {
                                for (k = 0; k < n + 1; k++)
                                {
                                        /* swapping mat[i][k] and mat[j][k] */
                                        mat[i][k] = mat[i][k] + mat[j][k];
                                        mat[j][k] = mat[i][k] - mat[j][k];
                                        mat[i][k] = mat[i][k] - mat[j][k];
                                }
                        }
                }
        }

        /* performing Gaussian elimination */
        for (i = 0; i < n - 1; i++)
        {
                for (j = i + 1; j < n; j++)
                {
                        float f = mat[j][i] / mat[i][i];
                        for (k = 0; k < n + 1; k++)
                        {
                                mat[j][k] = mat[j][k] - f * mat[i][k];
                        }
                }
        }
        /* Backward substitution for discovering values of unknowns */
        for (i = n - 1; i >= 0; i--)
        {
                res[i] = mat[i][n];

                for (j = i + 1; j < n; j++)
                {
                        if (i != j)
                        {
                                res[i] = res[i] - mat[i][j] * res[j];
                        }
                }
                res[i] = res[i] / mat[i][i];
        }

        if (wannaprint == true)
                printmatrix(mat);
        cout << "\nThe values of unknowns for the above equations :\n";
        for (i = 0; i < n; i++)
        {
                cout <<"x"<<i<<":\t"<< res[i] << "\n";
        }
}

void GaussJacobi(int n=-1)
{
        int i, j, k;
        if (n == -1)
        {
                cout << "\nEnter the no. of equations: ";
                cin >> n;
        }
        /* if no of equations are n then size of augmented matrix will be n*n+1. So here we are declaring 2d array 'mat' of size n+n+1 */
        vector<vector<float>> mat;

        /* for n equations there will be n unknowns which will be stored in array 'res' */
        float res[n];

        cout << "\nEnter the elements of the augmented matrix (Total " << n << " x " << (n + 1) << " elements):\
                \n(Make sure to enter them in Diagonally Dominant form )\n";
        for (i = 0; i < n; i++)
        {
                vector<float> temp;
                for (j = 0; j < n + 1; j++)
                {
                        int x;
                        cin >> x;
                        temp.push_back(x);
                }
                mat.push_back(temp);
        }

        
}

void printmatrix(vector<vector<float>> v)
{
        cout<<"\n The Matrix is ... \n";
        cout << "+";
        for (int i = 0; i <=v[0].size(); i++)
                cout << "--------";
        cout << "+\n";
        for (int i = 0; i < v.size(); i++)
        {
                cout << "|\t";
                for (int j = 0; j < v[i].size(); j++)
                        cout << v[i][j] << "\t";
                cout << " |\n";
        }
        cout << "+";
        for (int i = 0; i <=v[0].size(); i++)
                cout << "--------";
        cout << "+\n";
}

void dividendDifferenceTable(int places=8)
{
        int n=5;
        int difference=5;
        cout<<"How many values and n difference? : 5 5 \n";
        //cin>>n>>difference;
        cout<<"Enter the values:\n";

        /*-------------- Setting matrix---------------------*/
        double mat[n][difference+1];
        for(int i=0;i<n;i++)
                for(int j=0;j<difference+1;j++)
                        mat[i][j]=0;
        for(int i=0;i<n;i++)
                cin>>mat[i][0]>>mat[i][1];


        int k=0;
        for(int interation=1;interation<n;interation++)
        {
                for(int i=0;i<n-interation;i++)
                        mat[k++][interation+1]=(mat[i][interation]-mat[i+1][interation])/(mat[i][0]-mat[i+interation][0]);
                k=0;
        }




        /*---------- Printing Matrix---------------*/
        for(int i=0;i<n;i++,cout<<"\n")
                for(int j=0;j<difference+1;j++)
                        cout<< fixed << setprecision(places) << mat[i][j]<<"\t";
}
