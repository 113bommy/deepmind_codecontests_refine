#include <bits/stdc++.h>
int main() {
  double area, angA, angB, angR, numerador, denominador;
  int vert, rad;
  scanf("%d", &vert);
  scanf("%d", &rad);
  angA = 3.14159265358979323846 / vert;
  angB = angA / 2.0;
  angR = 3.14159265358979323846 - angA - angB;
  numerador = (pow(rad, 2) * sin(angB) * sin(angA));
  denominador = (2 * (sin(3.14159265358979323846 - 3 * angB)));
  area = numerador / denominador;
  area = area * vert * 2;
  printf("%.12lf", area);
  return 0;
}
