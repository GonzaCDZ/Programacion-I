#include <iostream>

 using namespace std;

 class Persona{
 public:

  Persona(string _nombre, unsigned short int _edad, unsigned short int _altura, unsigned short int _peso)
  {
    nombre = _nombre;
    edad = _edad;
    altura = _altura;
    peso = _peso;
  }
   //atributos
  string nombre;
  unsigned short edad;
  unsigned short altura;
  unsigned short peso;
};
 int main()
{
  string nombre;
  unsigned short int edad;
  unsigned short int altura;
  unsigned short int peso;
   cout << "Introduzca el nombre: ";
  cin >> nombre;
   cout << "Introduzca la edad de "<<nombre<<": ";
  cin >> edad;
   if(edad <= 0){
      cout << "ERROR. La edad tiene que ser mayor que 0"<<endl;
      return 1;
  }
  if(edad >= 120){
      cout << "ERROR. La edad tiene que ser menor que 120"<<endl;
      return 1;
  }
   cout << "Introduzca la altura en cm de "<<nombre<<": ";
  cin >> altura;
   if(altura <= 0){
      cout << "ERROR. La altura tiene que ser mayor que 0 cm"<<endl;
      return 1;
    }
   cout << "Introduzca el peso en kg de "<<nombre<<": ";
  cin >> peso;
   if(peso >= 170){
      cout << "ERROR. El peso tiene que ser menor de 170 kg" << endl;
      return 1;
    }
   Persona P(nombre, edad, altura, peso);
  cout << "Hola " << P.nombre << ", tienes " << P.edad << " años, mides "<< P.altura << "cm. "<< " y pesas " << P.peso << endl;
  return 0;
}
