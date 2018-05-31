#include <math.h> /* sin, cos */
#include <stdio.h> /* printf, scanf */

#define G 9.8 /* Acceleration due to gravity */
#define PI 3.14159

double compFlightTime(double hDispl, double mInitVel, double elevAngle);
double compHeight(double mInitVel, double elevAngle, double flightTime);

int main(void)
{
  double hDispl, mInitVel, elevAngle, flightTime, projHeight;

  printf("Enter horizontal displacement: "); /* Intake data */
  scanf("%lf", &hDispl);

  printf("Enter the magnitude of the initial velocity: ");
  scanf("%lf", &mInitVel);

  printf("Enter the initial engle of elevation: ");
  scanf("%lf", &elevAngle);

  /* perform computation */
  flightTime = compFlightTime(hDispl, mInitVel, elevAngle);
  projHeight = compHeight(mInitVel, elevAngle, flightTime);

  printf("Flight time is: %lf\nProjectile height is: %lf\n",
          flightTime, projHeight);


  return 0;
}

double compFlightTime(double hDispl, double mInitVel, double elevAngle)
{
  double value;
  value = hDispl/(mInitVel*cos((PI/180)*elevAngle));
  return value;
}

double compHeight(double mInitVel, double elevAngle, double flightTime)
{
  double value;
  value = mInitVel*sin((PI/180)*elevAngle)*flightTime-0.5*G*pow(flightTime, 2);
  return value;
}
