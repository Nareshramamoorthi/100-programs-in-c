// DSA Concept: 
#include <stdio.h>

// Function to calculate energy using Einstein's equation double calculateEnergy(double mass) { const double speedOfLight = 299792458; // meters per second return mass * speedOfLight * speedOfLight; }

int main() { double mass; printf("Enter mass in kilograms: "); scanf("%lf", &mass);

double energy = calculateEnergy(mass);
printf("Energy (E) = %.2e joules\n", energy);

return 0;

}

}