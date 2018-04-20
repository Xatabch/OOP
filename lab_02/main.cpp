#include <QCoreApplication>
#include <iostream>
#include "matrix.h"

int main(void)
{

    Matrix<int> matrix(3,5,4);
    if(matrix[0][4] == 4)
        std::cout << "ok";

    {//TESTS FOR OPERATOR =

        int m = 3;
        int n = 3;
        int check = 0;
        int errors = 0;

        Matrix<int> matrix(m,n,2);

        Matrix<int> matrix1(m,n);

        matrix1 = matrix;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix1[i][j] != 2)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        int m1 = 4;
        int n1 = 6;
        check = 0;

        Matrix<int> matrix2(m1,n1,2);

        Matrix<int> matrix3(m1,n1);

        matrix3 = matrix2;

        for(int i = 0; i < m1; i++)
        {
            for(int j = 0; j < n1; j++)
            {
                if(matrix3[i][j] != 2)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        int m2 = 1;
        int n2 = 1;
        check = 0;

        Matrix<int> matrix4(m2,n2,2);

        Matrix<int> matrix5(m2,n2);

        matrix5 = matrix4;

        for(int i = 0; i < m2; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(matrix5[i][j] != 2)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


//        int m3 = 4;
//        int n3 = 5;

//        int m4 = 2;
//        int n4 = 5;

//        check = 0;

//        Matrix<int> matrix6(m3,n3,2);

//        Matrix<int> matrix7(m4,n4);

//        matrix6 = matrix7;


        std::cout << "Passing test(s) " << 3 - errors << " from " << 3 << " (OPERATORS =)\n";

    }


    {//TESTS FOR OPERATORS - AND -=

        int m = 3;
        int n = 3;
        int check = 0;
        int errors = 0;

        int enter1[m][n] = {{10,20,30},{40,50,60},{70,80,90}};
        int real[m][n] = {{0,10,20},{30,40,50},{60,70,80}};

        Matrix<int> matrix1(m,n);

        matrix1.setMatrix(&enter1[0][0]);

        Matrix<int> matrix2(m,n,10);

        Matrix<int> result(m,n);

        result = matrix1 - matrix2;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(result[i][j] != real[i][j])
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        int m2 = 2;
        int n2 = 4;

        check = 0;

        int enter2[m2][n2] = {{10,20,30,40},{50,60,70,80}};
        int real2[m2][n2] = {{0,10,20,30},{40,50,60,70}};

        Matrix<int> matrix3(m2,n2);

        matrix3.setMatrix(&enter2[0][0]);

        Matrix<int> matrix4(m2,n2,10);

        Matrix<int> result2(m2,n2);

        result2 = matrix3 - matrix4;

        for(int i = 0; i < m2; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(result2[i][j] != real2[i][j])
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        int m4 = 3;
        int n4 = 6;

        Matrix<int> matrix5(m4,n4,20);

        Matrix<int> matrix6(m4,n4,10);

        matrix5 -= matrix6;

        for(int i = 0; i < m4; i++)
        {
            for(int j = 0; j < n4; j++)
            {
                if(matrix5[i][j] != 10)
                    check = 1;
            }
        }

        int m5 = 1;
        int n5 = 1;

        Matrix<int> matrix7(m5,n5,20);

        Matrix<int> matrix8(m5,n5,10);

        matrix7 -= matrix8;

        for(int i = 0; i < m5; i++)
        {
            for(int j = 0; j < n5; j++)
            {
                if(matrix7[i][j] != 10)
                    check = 1;
            }
        }

        std::cout << "Passing test(s) " << 4 - errors << " from " << 4 << " (OPERATORS - AND -=)\n";

    }


    {//TESTS FOR OPERATOR *

        int m = 3;
        int n = 2;
        int m1 = 2;
        int n1 = 5;
        int m2 = 3;
        int n2 = 5;

        int check = 0;
        int errors = 0;

        Matrix<int> matrix1(m,n,2);

        Matrix<int> matrix2(m1,n1,3);

        Matrix<int> result(m2,n2);

        result = matrix1 * matrix2;

        for(int i = 0; i < m2; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(result[i][j] != 12)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        m = 3;
        n = 3;
        m1 = 3;
        n1 = 3;
        m2 = 3;
        n2 = 3;

        check = 0;

        Matrix<int> matrix3(m,n,2);

        Matrix<int> matrix4(m1,n1,3);

        Matrix<int> result2(m2,n2);

        result2 = matrix3 * matrix4;

        for(int i = 0; i < m2; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(result2[i][j] != 18)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;

        std::cout << "Passing test(s) " << 2 - errors << " from " << 2 << " (OPERATORS *)\n";

    }


    {//TESTS FOR METHOD setMatrix(T *)

        int m = 3;
        int n = 3;
        int check = 0;
        int errors = 0;

        int enter1[n][m] = {{1,2,3},{4,5,6},{7,8,9}};
        int real[n][m] = {{1,2,3},{4,5,6},{7,8,9}};

        Matrix<int> matrix1(m,n);

        matrix1.setMatrix(&enter1[0][0]);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix1[i][j] != real[i][j])
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;

        std::cout << "Passing test(s) " << 1 - errors << " from " << 1 << " (METHOD setMatrix(T *))\n";

    }


    {
        //TESTS FOR OPERATOR + AND +=
        int m = 3;
        int n = 3;
        int check = 0;
        int errors = 0;

        int enter1[n][m] = {{1,2,3},{4,5,6},{7,8,9}};
        int enter2[n][m] = {{10,11,12},{13,14,15},{16,17,18}};
        int real[n][m] = {{11,13,15},{17,19,21},{23,25,27}};

        Matrix<int> matrix1(m,n);

        matrix1.setMatrix(&enter1[0][0]);

        Matrix<int> matrix2(m,n);

        matrix2.setMatrix(&enter2[0][0]);

        Matrix<int> result(m,n);

        result = matrix1 + matrix2;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(result[i][j] != real[i][j])
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        m = 3;
        n = 6;
        check = 0;

        Matrix<int> matrix3(m,n,3);

        Matrix<int> matrix4(m,n,2);

        Matrix<int> result2(m,n);

        result2 = matrix3 + matrix4;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(result2[i][j] != 5)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        m = 3;
        n = 5;
        check = 0;

        Matrix<int> matrix5(m,n);

        Matrix<int> matrix6(m,n,2);

        matrix5 += matrix6;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix5[i][j] != 2)
                    check = 1;
            }
        }

        if(check == 1)
            errors += 1;


        m = 1;
        n = 1;

        Matrix<int> matrix7(m,n,20);

        Matrix<int> matrix8(m,n,10);

        matrix7 += matrix8;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix7[i][j] != 30)
                    check = 1;
            }
        }


        std::cout << "Passing test(s) " << 4 - errors << " from " << 4 << " (OPERATORS + AND +=)\n";
    }

   {
        //TESTS FOR OPERATOR[]
        int m = 3;
        int n = 3;
        int errors = 0;

        int enter1[m][n] = {{1,2,3},{4,5,6},{7,8,9}};

        Matrix<int> matrix1(m,n);

        matrix1.setMatrix(&enter1[0][0]);

        if(matrix1[1][2] != 6)
            errors += 1;

        std::cout << "Passing test(s) " << 1 - errors << " from " << 1 << " (OPERATOR [])\n";

   }


}
