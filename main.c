#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define EPS 1e-5

double Sqrt(double a,int b);
double Pow(double x,double y)
{
    double i,extra,need=1;
    double result=1;
    double true_result;
    if(y==0)
    {
        return 1;
    }
    else if(y>0)
    {
        extra = y - floor(y);
        if(extra==0)
        {
           for(i=1;i<=y;i++)
           {
               result = result*x;
           }
           return result;
        }
        else
        {

            while(extra!=0)
            {
                y = y*10;
                need = need*10;
                extra = y - floor(y);
            }
            for(i=1;i<=y;i++)
            {
                result = result*x;
            }
            true_result = Sqrt(result,need);
            return true_result;
        }
    }
    else
    {
        extra = y - floor(y);
        y = -y;
        if(extra==0)
        {
           for(i=1;i<=y;i++)
           {
               result = result*x;
           }
           result = 1.0/result;
           return result;
        }
        else
        {

            while(extra!=0)
            {
                y = y*10;
                need = need*10;
                extra = y - floor(y);
            }
            for(i=1;i<=y;i++)
            {
                result = result*x;
            }
            true_result = Sqrt(result,need);
            true_result = 1.0/true_result;
            return true_result;
        }
    }
}

double Sqrt(double a,int b)
{
    double maybe,mid,l,another_result,r;
    mid = a/2.0;
    l = 0;
    r = a;
    if(b%2==0 && a<0)
    {
        printf("Input error!");
    }
    else
    {
       do
    {

        maybe = pow(mid,b);
        if(maybe>a)
        {
            r = mid;
            mid = (mid+l)/2.0;
        }
        else if(maybe<a)
        {
            l = mid;
            mid = (mid+r)/2.0;
        }
        else
        {
            another_result = mid;
            return another_result;
        }

    }while(fabs(a-maybe)>=EPS);
    another_result = mid;
    return another_result;
    }
}

int main()
{
    double m,n;
    double ret;
    printf("Input m and n:");
    scanf("%lf,%lf",&m,&n);
    ret = Pow(m,n);
    printf("%.1lf^%.1lf = %.4lf\n",m,n,ret);
    return 0;
}
