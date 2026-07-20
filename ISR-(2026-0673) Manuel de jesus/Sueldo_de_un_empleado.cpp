#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double salarioBruto, tss, salarioNetoMensual, salarioAnual, isrAnual, isrMensual;
    const double TASA_TSS = 0.0591;

    cout << "--- Calculadora de ISR 2026 (Republica Dominicana) ---" << endl;
    cout << "Ingrese el sueldo mensual bruto: ";
    cin >> salarioBruto;

    tss = salarioBruto * TASA_TSS;
    salarioNetoMensual = salarioBruto - tss;
    salarioAnual = salarioNetoMensual * 12;

    // Escala Anual 2026
    if (salarioAnual <= 416220.00) {
        isrAnual = 0;
    }
    else if (salarioAnual <= 624329.00) {
        isrAnual = (salarioAnual - 416220.01) * 0.15;
    }
    else if (salarioAnual <= 867123.00) {
        isrAnual = 31216.00 + (salarioAnual - 624329.01) * 0.20;
    }
    else {
        isrAnual = 79776.00 + (salarioAnual - 867123.01) * 0.25;
    }

    isrMensual = isrAnual / 12;

    cout << fixed << setprecision(2);
    cout << "\n--- Resultados ---" << endl;
    cout << "Sueldo Bruto: RD$" << salarioBruto << endl;
    cout << "Descuento TSS: RD$" << tss << endl;
    if (isrMensual > 0) {
        cout << "ISR a descontar: RD$" << isrMensual << endl;
    }
    else {
        cout << "ISR a descontar: N/A (Exento)" << endl;
    }

    return 0;
}