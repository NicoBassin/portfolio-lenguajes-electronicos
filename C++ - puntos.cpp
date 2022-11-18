#include<iostream>
#include<math.h>

#define DEF_X 0
#define DEF_Y 0
#define DEF_NAME "nombre_predeterminado"
#define DEF_COLOR "color_predeterminado"
#define DEF_THICKNESS 3

using namespace std;

class point{
    private:
        float x;
        float y;
        string name;
        string color;
        int thickness;
    public:
        point(); // (0; 0)
        point(float, float); // (x; y)
        point(float, float, string); //(x; y; name)
        point(float, float, string, string, int); //(x; y; name; color; thickness)

        void SetX(float);
        void SetY(float);
        void SetCoords(float, float);
        void SetName(string);
        void SetColor(string);
        void SetThickness(int);
       
        float GetX(void);
        float GetY(void);
        string GetName(void);
        string GetColor(void);
        int GetThickness(void);
       
        float GetDistanceToOrigin(void);
        float GetDistanceToPoint(point);
        void DrawLineToPoint(point);
};

//Constructores

point::point(void){
    this->x = DEF_X;
    this->y = DEF_Y;
    this->name = DEF_NAME;
    this->color = DEF_COLOR;
    this->thickness = DEF_THICKNESS;
}

point::point(float _x, float _y){
    this->x = _x;
    this->y = _y;
    this->name = DEF_NAME;
    this->color = DEF_COLOR;
    this->thickness = DEF_THICKNESS;
}

point::point(float _x, float _y, string _name){
    this->x = _x;
    this->y = _y;
    this->name = _name;
    this->color = DEF_COLOR;
    this->thickness = DEF_THICKNESS;
}

point::point(float _x, float _y, string _name, string _color, int _thickness){
    this->x = _x;
    this->y = _y;
    this->name = _name;
    this->color = _color;
    this->thickness = _thickness;
}

//Setters

void point::SetX(float _x){
    this->x = _x;
}

void point::SetY(float _y){
    this->y = _y;
}

void point::SetCoords(float _x, float _y){
    this->x = _x;
    this->y = _y;
}

void point::SetName(string _name){
    this->name = _name;
}

void point::SetColor(string _color){
    this->color = _color;
}

void point::SetThickness(int _thickness){
    this->thickness = _thickness;
}

//Getters

float point::GetY(void){
    return this->y;
}

float point::GetX(void){
    return this->x;
}

string point::GetName(void){
    return this->name;
}

string point::GetColor(void){
    return this->color;
}

int point::GetThickness(void){
    return this->thickness;
}

float point::GetDistanceToOrigin(void){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float point::GetDistanceToPoint(point punto){
    //(a; b) --> (c; d) = sqrt(pow((a-c), 2) + pow((b-d), 2))
    return sqrt(pow( (this->x)-(punto.GetX() ), 2) + pow( (this->y)-(punto.GetY()) , 2));
}

//Sobrecarga de operadores!

point operator + (point a, point b){            // (ax+by)+(cx+dy) = (a+c)x + (b+d)y
    point total;

    total = point(a.GetX() + b.GetX(), a.GetY() + b.GetY(), a.GetName(), a.GetColor(), a.GetThickness());

    return total;
}

point operator - (point a, point b){            // (ax+by)-(cx+dy) = (a-c)x + (b-d)y
    point total;
    
    total = point(a.GetX() - b.GetX(), a.GetY() - b.GetY(), a.GetName(), a.GetColor(), a.GetThickness());

    return total;
}

point operator * (point puntoA, point puntoB){ // (ax+by) * (cx+dy) = (ac-bd)x + (ad+bc)y
    point total;

    float a = puntoA.GetX();
    float b = puntoA.GetY();
    float c = puntoB.GetX();
    float d = puntoB.GetY();

    float coordX = a * c - b * d;
    float coordY = a * d + b * c;

    total = point(coordX, coordY, puntoA.GetName(), puntoA.GetColor(), puntoA.GetThickness());

    return total;
}

point operator / (point puntoA, point puntoB){  // (ax+by) / (cx+dy) = [(ac+bd)/(c^2-d^2)]x + [(bc-ad)/(c^2-d^2)]y
    point total;

    float a = puntoA.GetX();
    float b = puntoA.GetY();
    float c = puntoB.GetX();
    float d = puntoB.GetY();    

    float coordX = (a * c + b * d) / (pow(c, 2) - (pow(d, 2)));
    float coordY = (b * c - a * d) / (pow(c, 2) - (pow(d, 2)));
    
    total = point(coordX, coordY, puntoA.GetName(), puntoA.GetColor(), puntoA.GetThickness());

    return total;
}

//Funcion principal main
int main(void){
    point primerPunto;
    point segundoPunto;
    point tercerPunto;
    
    primerPunto = point(3, 6);
    segundoPunto = point(5, 14);
    tercerPunto = point();
    
    int x, y;

    cout<<"Ingrese la coordenada X de un punto (sera el numero 3): ";
    cin>>x; 
    tercerPunto.SetX(x);
    
    cout<<"Ingrese la coordenada Y de un punto (sera el numero 3): ";
    cin>>y;
    tercerPunto.SetY(y);
    
    cout<<endl<<"primer punto autogenerado: ("<<primerPunto.GetX()<<"; "<<primerPunto.GetY()<<")"<<endl;
    cout<<"distancia al origen de coordenadas: "<<primerPunto.GetDistanceToOrigin()<<endl;
    cout<<"nombre: "<<primerPunto.GetName()<<endl;
    cout<<"color: "<<primerPunto.GetColor()<<endl;
    cout<<"grosor: "<<primerPunto.GetThickness()<<endl;
    
    cout<<endl<<"segundo punto autogenerado: ("<<segundoPunto.GetX()<<"; "<<segundoPunto.GetY()<<")"<<endl;
    cout<<"distancia al origen de coordenadas: "<<segundoPunto.GetDistanceToOrigin()<<endl;
    cout<<"nombre: "<<segundoPunto.GetName()<<endl;
    cout<<"color: "<<segundoPunto.GetColor()<<endl;
    cout<<"grosor: "<<segundoPunto.GetThickness()<<endl;
    
    cout<<endl<<"distancia entre los puntos ("<<primerPunto.GetX()<<"; "<<primerPunto.GetY()<<") y ("<<tercerPunto.GetX()<<"; "<<tercerPunto.GetY()<<"): "<<primerPunto.GetDistanceToPoint(tercerPunto)<<endl;

    cout<<endl<<"suma de los puntos 1 y 2: ("<<(primerPunto+segundoPunto).GetX()<<"; "<<(primerPunto+segundoPunto).GetY()<<")"<<endl;
    cout<<"resta de los puntos 1 y 2: ("<<(primerPunto-segundoPunto).GetX()<<"; "<<(primerPunto-segundoPunto).GetY()<<")"<<endl;
    cout<<"multiplicacion de los puntos 1 y 2: ("<<(primerPunto*segundoPunto).GetX()<<"; "<<(primerPunto*segundoPunto).GetY()<<")"<<endl;
    cout<<"division de los puntos 1 y 2: ("<<(primerPunto/segundoPunto).GetX()<<"; "<<(primerPunto/segundoPunto).GetY()<<")"<<endl;


    return 0;
}
