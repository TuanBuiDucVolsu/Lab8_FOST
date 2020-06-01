#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
std::ofstream output_file("data.txt");
short int L = 1;
short int D = 1;
short int tmax = 4;
double h = 0.02;
double tau = h*h / (2*D);
double N = L / h;
double M = tmax / tau;
double *T_cur = new double[int(N)+1];
double *T_next = new double[int(N)+1];

T_cur[0] = 10;

for (int i = 1; i <= N; i++){
    T_cur[i] = 0;
}

for (int t = 0; t < int(M) + 1; t++){

        int k = 0;                // флаг для печати только одного t в файл

        for (int x = 0; x < int(N) + 1; x++){

            T_next[x] = tau*D / (h*h) * T_cur[x+1] + (1 - 2*tau*D / ((h*h))) * T_cur[x] + tau*D / ((h*h)) * T_cur[x - 1]; // вычисление Т

            if (t == 0){

                if (k == 0){
                    output_file << "t = " << t << std::endl << std::endl;
                    k++;
                }
                output_file << "x = " << x << "\tT = " << T_next[x] << std::endl;
            }
            else if (t == int(M)/2){

                if (k == 0){
                    output_file << std::endl << std::endl << "t = " << tmax/2 << std::endl << std::endl;
                    k++;
                }
                output_file << "x = " << x << "\tT = " << T_next[x] << std::endl;
            }
            else if (t == int(M)){

                if (k == 0){
                    output_file << std::endl << std::endl << "t = " << tmax << std::endl << std::endl;
                    k++;
                }
                output_file << "x = " << x << "\tT = " << T_next[x] << std::endl;
            }
        }



        for (int i = 0; i <= N; i++){

            T_cur[i] = T_next[i];
        }
    }
	return 0;
}
