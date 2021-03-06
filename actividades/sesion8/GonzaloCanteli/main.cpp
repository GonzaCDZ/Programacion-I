#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Vector{
public:

    Vector(unsigned int n)
    {
            if (n < 2) {
                throw string{"numero de coordenadas incorrecto"};
            }
            size = n;
            for(unsigned int i=0; i<n; i++){
                v.push_back(0);
            }
     }

     void setElement(unsigned int index,float valor)
     {
            if(index >= size ) {
                throw string{"El indice esta fuera del rango"};
            }
            v.at(index)=valor;
     }
     float module()
     {
            float suma{0};
            for (auto elem: v) {
                suma += elem*elem;
            }
            return sqrt(suma);
     }
     Vector unitario()
     {
            float m = module();
            if( m == 0) throw string{"No existe el vector unitario "};
            Vector unitario(size);
            for(unsigned int i=0; i < size; i++){
                unitario.setElement(i,v.at(i)/m);
            }
            return unitario;
            }


     unsigned int getSize(){
           return size;
     }

     float getElement(unsigned int index)
     {
            if(index >= size ) {
                throw string{"Indice fuera del rango"};
            }
            return v.at(index);
     }

     void print()
     {
            cout << "[";
            for(auto elem:v){
                cout << elem << ",";
            }
            cout << "]" << endl;
     }
private:
    vector<float>v;
    unsigned int size;

};

Vector add(Vector a, Vector b)
{
    Vector suma(a.getSize());

    if(a.getSize() != b.getSize()) throw string{"La suma no puede realizarse"};

    for(unsigned int i=0; i < a.getSize(); i++) {
        suma.setElement( i, a.getElement(i) + b.getElement(i));
    }
    return suma;
}

float PEscalar(Vector a, Vector b)
{
    float result{0};

    if(a.getSize() != b.getSize()){
        throw string{"El escalar resultante es invalido"};
    }
    for(unsigned int i=0; i<a.getSize(); i++){
        result = result+a.getElement(i)*b.getElement(i);
    }
    return result;
}

bool Perpendiculares(Vector a, Vector b)
{
    return ( PEscalar(a,b) == 0 );
}

float ARadianes(Vector a, Vector b)
{
    float escalar,modulo1,modulo2,angulo;

    if(a.getSize() != 3 || b.getSize() != 3){
        throw string{"No se puede calcular el angulo"};
    }
    escalar=PEscalar(a,b);
    modulo1=a.module();
    modulo2=b.module();
    angulo =acos(escalar/(modulo1*modulo2));
    return angulo;
}

Vector productoVectorial(Vector a, Vector b)
{
    Vector c(3);

    if(a.getSize() != 3 || b.getSize() != 3){
        throw string{"No se puede calcular el producto vectorial"};
    }
    c.setElement(0,a.getElement(1)*b.getElement(2)-b.getElement(1)*a.getElement(2));
    c.setElement(1,a.getElement(2)*b.getElement(0)-b.getElement(2)*a.getElement(0));
    c.setElement(2,a.getElement(0)*b.getElement(1)-b.getElement(0)*a.getElement(1));
    return c;
}

int main()
{
    try{
        Vector miVector1(3);
        Vector miVector2(3);
        Vector miVector3(3);
        Vector miVector4(3);
        Vector miVector5(3);

        float escalar, angulo;

        cout << "Introduce numeros: " << endl;
        for(unsigned int i=0; i<3; i++){
            float aux;
            cin >> aux;
            miVector1.setElement(i,aux);
        }
        cout << "El vector actual es: ";
        miVector1.print(); cout << endl;


        cout << "el modulo del vector es:  " << miVector1.module() << endl << endl;

        miVector2= miVector1.unitario();

        miVector2.print();

        cout << "El vector unitario es: "<< endl;;

        miVector2=add(miVector1,miVector2);

        miVector2.print();
        cout << "La suma del vector con su unitario es: "<< endl;


        escalar=PEscalar(miVector1,miVector2);
        cout << "El producto escalar entre el vector y su unitario es:  " << escalar << endl;

        if ( Perpendiculares(miVector1,miVector2) )
             cout << "Los Vectores 1 y 2 son perpendiculares" << endl;
        else
             cout << "Los Vectores 1 y 2 no son perpendiculares" << endl;


        angulo = ARadianes(miVector1,miVector2);
        cout << "El angulo entre el primer y el segundo vector es: " << angulo << "  radianes" << endl;


        cout << "introduce valores: " << endl;
        for(unsigned int i=0; i<3; i++){
                    float aux;
                    cin >> aux;
                    miVector4.setElement(i,aux);
        }

        miVector5 = productoVectorial(miVector2,miVector4);
        cout << "El vector perpendicular a los vectores 2 y 4 es: "<< endl;

        angulo = ARadianes(miVector2,miVector5);
        miVector5.print();
        cout << "El angulo entre el segundo y el quinto vector es de: " << angulo << "  radianes" << endl;


    } catch(string e){
        cout << e << endl;
        return 0;
    }
}
