// A software development team aimed to design a versatile utility that could perform basic arithmetic

// operations while demonstrating the concept of function overloading. This effort resulted in a class-
// based calculator system capable of handling various combinations of input types, such as integers and

// floating-point numbers. The system includes multiple overloaded add functions, each tailored to
// accept distinct input types and perform addition operations accordingly. This approach ensures the
// calculator is adaptable and provides consistent functionality regardless of the input types.
// The case revolves around testing and validating the versatility of this calculator. Participants are
// expected to create instances of the calculator, invoke the appropriate overloaded functions for various
// input scenarios, and store the resulting values for further analysis. To organize and display these
// results, the system incorporates methods to sequentially process and present the outcomes.

#include<iostream>
using namespace std;

class Calculater{

    public:

    int add (int num1,int num2)
    {
          int sum=num1+num2;
          cout<<"Sum of "<<num1<<" and "<<num2<<" is: "<<sum<<endl;
    }

    float add (float num1,float num2)
    {
        float sum=num1+num2;
       cout<<"Sum of "<<num1<<" and "<<num2<<" is: "<<sum<<endl;
    }

};

int main()
{
    Calculater num;

   num.add(2,4);
   num.add(5.26f,9.65f);
 return 0;
}
