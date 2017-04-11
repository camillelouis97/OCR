#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double sigmoid(double x){
    return 1 / (1 + exp(-x));
}

double derivative(double x){
    return x * (1 - x);
}

double output(double in[], double w[], double b){
    double res = 0;
    size_t len = sizeof(in) / sizeof(in[0]);
    for(size_t i = 0; i < len; ++i)
        res += in[i] * w[i];
    res += b
    return sigmoid(res);
}

void train(){

    //nbinput = nombre de neurones dans la premiere couche (a determiner plus tard)
    //nbhinput = nombre de neurones dans la couche cache (a determiner plus tard)
    // 26 = nb de lettres dans l'alphabet

    double in[nbinput];
    double res[26];

    double w1[nbhinput], input1[nbhinput], err1, b1;
    b1 = (double) rand() / (double) RAND_MAX;
    double w2[26], input2[26], err2, b2;
    b2 = (double) rand() / (double) RAND_MAX;

    for(int i = 0; i < nbhinput; ++i){
        w1[i] = (double) rand() / (double) RAND_MAX;
        w2[i] = (double) rand() / (double) RAND_MAX;

        int epoch = 0;
        while(epoch < 2000){
            ++epoch;
            for(int j = 0; j < nbinput; ++j){
                input1[j] = in[j];

                input2[j] = output(input1[j], w1, b1);

                double outputf = output(input2, w2, b2);

                err2 = derrivative(outputf) * (res[j] - outputf);
                w2[i] += err2 * input2[i];
                b2 += err2;

                err1 = derivative(input2[i]) * err2 * w2[i];
                w1[i] += err1 * input1[i];
                b1 += err1;
            }
        }
    }

    int main() {
        train();
        return 0;
    }
}
