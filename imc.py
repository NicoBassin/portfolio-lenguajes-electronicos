Usuario = {
    "nombre":"",
    "apellido":"",
    "edad":0,
    "peso":0,
    "altura":0,
    "direccion":"",
    "telefono":"",
    "mail":""
}

def CalcularIMC():
    try:
        return round(float(Usuario["peso"]) / (float(Usuario["altura"])**2), 2)
    except:
        return -1

def cat_imc(imc):
    if(imc < 18.5):    print("Bajo peso")
    elif(imc < 24.9):  print("Peso normal")
    elif(imc < 29.9):  print("Sobre peso")
    elif(imc < 34.9):  print("Obesidad tipo I")
    elif(imc < 39.9):  print("Obesidad tipo II")
    else:              print("Obesidad tipo III")

def ImprimirDatos(Usuario):
    print("\n")
    for key in Usuario.keys():
        print(f"Su {key} es {Usuario[key]}")
    if(CalcularIMC() != -1):
        print(f"Su IMC es {CalcularIMC()}")
        cat_imc(CalcularIMC())
    else:
        print("No se pudo calcular su IMC. Peso o altura incorrectos.")

for key in Usuario.keys():
    Usuario[key] = input(f'Ingrese su {key}: ').upper()
    while key == "mail" and "@" not in (Usuario[key]):
        Usuario[key] = input(f'Ingrese su {key} de nuevo: ').upper()

ImprimirDatos(Usuario)
input("Presione ENTER para salir del programa.")