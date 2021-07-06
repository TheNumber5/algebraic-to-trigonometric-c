#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> //TODO: use less libraries

//Converter of complex numbers from algebraic form to trigonometric form
//Version: 1.2b

typedef struct algebraic_complex {
    float real;
    float imaginary;
} algebraic_cmp;

typedef struct trigonometric_complex {
    float modulus;
    float argument;
    //TODO: make better names for these
} trigonometric_cmp;

float pi = 3.14159265;

void transform_to_trigonometric(float algebraic_real, float algebraic_complex, unsigned int mode, FILE* out_file) {
    algebraic_cmp number_alg;
    trigonometric_cmp number_trig;
    number_alg.real = algebraic_real;
    number_alg.imaginary = algebraic_complex;
	if(number_alg.imaginary==0 && number_alg.real>0) {
		number_trig.argument = 0;
	}
	else if(number_alg.imaginary==0 && number_alg.real<0) {
		number_trig.argument = pi;
	}
	else if(number_alg.imaginary>0 && number_alg.real==0) {
		number_trig.argument = pi/2;
	}
	else if(number_alg.imaginary<0 && number_alg.real==0) {
		number_trig.argument = 3*pi/2;
	}
    if(number_alg.real>0 && number_alg.imaginary>0) {
        number_trig.argument = atan(number_alg.imaginary/number_alg.real);
    }
    else if(number_alg.real<0 && number_alg.imaginary>0) {
        number_alg.real = fabsf(number_alg.real);
        //---------------------//
        number_trig.argument = atan(number_alg.imaginary/number_alg.real)+pi/2;
    }
    else if(number_alg.real<0 && number_alg.imaginary<0) {
        number_alg.real = fabsf(number_alg.real);
        number_alg.imaginary = fabsf(number_alg.imaginary);
        //---------------------//
        number_trig.argument = atan(number_alg.imaginary/number_alg.real)+pi;
    }
    else if(number_alg.real>0 && number_alg.imaginary<0) {
        number_alg.imaginary = fabsf(number_alg.imaginary);
        //---------------------//
        number_trig.argument = atan(number_alg.imaginary/number_alg.real)+3*pi/2;
    } //TODO: make this be less stupid, this is very bad

    number_trig.modulus = sqrt(number_alg.real*number_alg.real+number_alg.imaginary*number_alg.imaginary); //This remains the same
    if(mode == 1) {
    printf("%f %f", number_trig.modulus, number_trig.argument);
    }
    else if(mode == 2){
    fprintf(out_file, "%f %f\n", number_trig.modulus, number_trig.argument);
    }
}

int main(int argc, char** argv) {
    float real, imaginary;
    if(!strcmp(argv[1], "-d")) {
        real = atof(argv[2]);
        imaginary = atof(argv[3]);
        transform_to_trigonometric(real, imaginary, 1, 0);
        }
    else if (!strcmp(argv[1], "-f")) {
        FILE *in_file, *out_file;
        in_file = fopen(argv[2], "rb");
        out_file = fopen(argv[3], "wb");
        do{
        fscanf(in_file, "%f", &real);
        fscanf(in_file, "%f", &imaginary);
        transform_to_trigonometric(real, imaginary, 2, out_file);
        } while(!feof(in_file));
    fclose(in_file);
    fclose(out_file);
    }
    else if (!strcmp(argv[1], "-b")){
        clock_t tick = clock();
        for(int i=0; i<atoi(argv[2]); i++) {
        real = rand()%1000000;
        imaginary = rand()%1000000;
        transform_to_trigonometric(real, imaginary, 3, 0);
        }
        clock_t tock = clock();
        double benchmark_time = (double)(tock-tick)/CLOCKS_PER_SEC;
        printf("Benchmark time: %fms", benchmark_time); //Weird way to benchmark a computer
    }
return 0;
}
