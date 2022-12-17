/***************************************************************/
/**                                                           **/
/**   Matheus                                                 **/
/**   Exercício-Programa 02                                   **/
/**   Professor: Y. K.                                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <math.h>

double dist(double p1x, double p1y, double p2x, double p2y);

double forca(char c, int i, double x0, double y0, double m0, double x1, double y1, double m1, 
double x2, double y2, double m2);

void atualize(double *x, double *y, double *vx, double *vy, double ax, double ay, double dt);


int main(){

    int i;
    double rax, ray, vax, vay, ma;
    double rbx, rby, vbx, vby, mb;  
    double rcx, rcy, vcx, vcy, mc;
    double t, dt;
    double aax, aay, abx, aby, acx, acy;

    scanf("%lf %lf %lf %lf %lf", &rax, &ray, &vax, &vay, &ma);
    scanf("%lf %lf %lf %lf %lf", &rbx, &rby, &vbx, &vby, &mb);
    scanf("%lf %lf %lf %lf %lf", &rcx, &rcy, &vcx, &vcy, &mc);

    scanf("%lf", &t);
    scanf("%lf", &dt);
    printf("%.6g %.6g %.6g %.6g %.6g %.6g\n", rax, ray, rbx, rby, rcx, rcy);

    for(i=0;i<t;i+=dt){

        aax=(1/ma)*forca('x',0,rax,ray,ma,rbx,rby,mb,rcx,rcy,mc);
        aay=(1/ma)*forca('y',0,rax,ray,ma,rbx,rby,mb,rcx,rcy,mc);
        abx=(1/mb)*forca('x',1,rax,ray,ma,rbx,rby,mb,rcx,rcy,mc);
        aby=(1/mb)*forca('y',1,rax,ray,ma,rbx,rby,mb,rcx,rcy,mc);
        acx=(1/mc)*forca('x',2,rax,ray,ma,rbx,rby,mb,rcx,rcy,mc);
        acy=(1/mc)*forca('y',2,rax,ray,ma,rbx,rby,mb,rcx,rcy,mc);

        atualize(&rax, &ray, &vax, &vay, aax, aay, dt);
        atualize(&rbx, &rby, &vbx, &vby, abx, aby, dt);
        atualize(&rcx, &rcy, &vcx, &vcy, acx, acy, dt);

        printf("%.6g %.6g %.6g %.6g %.6g %.6g\n", rax, ray, rbx, rby, rcx, rcy);
    }

    return 0;
}

double dist(double p1x, double p1y, double p2x, double p2y){    

    return(sqrt((p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y))); /*vem do Teorema de Pitagoras*/
}

double forca(char c, int i, double x0, double y0, double m0, double x1, double y1, double m1, 
double x2, double y2, double m2){

    double G=6.67e-11;
    double F1c=0;
    double F2c=0;
    if(c=='x'){
        if(i==0){
            F1c=(G*m0*m1/(pow(dist(x0,y0,x1,y1),3.0)))*(x1-x0);
            F2c=(G*m0*m2/(pow(dist(x0,y0,x2,y2),3.0)))*(x2-x0);
        }
        else if(i==1){
            F1c=(G*m1*m0/(pow(dist(x0,y0,x1,y1),3.0)))*(x0-x1);
            F2c=(G*m1*m2/(pow(dist(x1,y1,x2,y2),3.0)))*(x2-x1);
        }
        else if(i==2){
            F1c=(G*m2*m1/(pow(dist(x2,y2,x1,y1),3.0)))*(x1-x2);
            F2c=(G*m0*m2/(pow(dist(x0,y0,x2,y2),3.0)))*(x0-x2);
        }
    }
    else if(c=='y'){ /*poderia deixar apenas o else, utilizei mais uma condicao pra evitar problemas com entradas estranhas*/
        if(i==0){
            F1c=(G*m0*m1/(pow(dist(x0,y0,x1,y1),3.0)))*(y1-y0);
            F2c=(G*m0*m2/(pow(dist(x0,y0,x2,y2),3.0)))*(y2-y0);
        }
        else if(i==1){
            F1c=(G*m1*m0/(pow(dist(x0,y0,x1,y1),3.0)))*(y0-y1);
            F2c=(G*m1*m2/(pow(dist(x1,y1,x2,y2),3.0)))*(y2-y1);
        }
        else if(i==2){
            F1c=(G*m2*m1/(pow(dist(x2,y2,x1,y1),3.0)))*(y1-y2);
            F2c=(G*m0*m2/(pow(dist(x0,y0,x2,y2),3.0)))*(y0-y2);
        }
    }
    return(F1c+F2c);
}

void atualize(double *x, double *y, double *vx, double *vy, double ax, double ay, double dt){

    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;

    *x = *x + *vx * dt;         /*atualiza por meio de referencia os valores das variaveis*/
    *y = *y + *vy * dt;

}

