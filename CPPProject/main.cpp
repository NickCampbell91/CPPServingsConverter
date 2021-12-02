#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Recipe {
    public:
        float oldServings = 0;
        float newServings = 0;
        string ingredient = "";
        float measurement = 0;
        int unit = 0;

        int getType() {
            cout << "Enter the servings stated in the original recipe:\n";
            cin >> oldServings;
            cout << "Enter the amount of servings you want to make:\n";
            cin >> newServings;
            cout << "Enter the ingredient:\n";
            cin >> ingredient;
            cout << "Enter the measurement:\n";
            cin >> measurement;
            cout << "Enter the measurement unit:\n";
            cout << "1: Cups" << endl;
            cout << "2: Half-Cups" << endl;
            cout << "3: Third-Cups" << endl;
            cout << "4: Quarter-Cups" << endl;
            cout << "5: Tablespoons" << endl;
            cout << "6: Teaspoons" << endl;
            cin >> unit;

            return unit;
        }
};

class Simplify {
    public:
        float a = 0;
        int cups = 0;
        int halfCups = 0;
        int thirdCups = 0;
        int quarterCups = 0;
        int tablespoons = 0;
        int teaspoons = 0;

        int simplifyMeasurement(float measurement) {
            a = measurement;

            // Store number of whole cups in var
            while (a >= 1) {
                a--;
                cups++;
            }

            // If at or above 3/4 cups, remaining amount will be divided between
            // three quarter cups and whatever tablespoons and teaspoons remain.
            if (a >= .75) {
                a -= .75;
                quarterCups += 3;

                if (a >= 0.0625 && fmod(a,0.0625) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0625;
                        tablespoons++;
                    }
                }
                if (fmod(a,0.0208333) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0208333;
                        teaspoons++;
                    }
                }
            }

            // If at or above 2/3 cups, remaining amount will be divided between
            // two third cups and whatever tablespoons and teaspoons remain.
            else if (a >= 0.666) {
                // cout << a << endl;
                a -= 0.666;
                thirdCups += 2;

                if (a >= 0.0625 && fmod(a,0.0625) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0625;
                        tablespoons++;
                    }
                }
                if (fmod(a,0.0208333) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0208333;
                        teaspoons++;
                    }
                }
            }

            // If at or above 1/2 cup, remaining amount will be divided between
            // one half cup and whatever tablespoons and teaspoons remain.
            else if (a >= .5) {
                a -= .5;
                halfCups += 1;

                if (a >= 0.0625 && fmod(a,0.0625) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0625;
                        tablespoons++;
                    }
                }
                if (fmod(a,0.0208333) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0208333;
                        teaspoons++;
                    }
                }
            }

            // If at or above 1/3 cup, remaining amount will be divided between
            // one third cup and whatever tablespoons and teaspoons remain.
            else if (a >= 0.333) {
                a -= 0.333;
                thirdCups += 1;

                if (a >= 0.0625 && fmod(a,0.0625) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0625;
                        tablespoons++;
                    }
                }
                if (fmod(a,0.0208333) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0208333;
                        teaspoons++;
                    }
                }
            }

            // If at or above 1/4 cup, remaining amount will be divided between
            // one half cup and whatever tablespoons and teaspoons remain.
            else if (a >= .25) {
                a -= .25;
                quarterCups += 1;

                if (a >= 0.0625 && fmod(a,0.0625) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0625;
                        tablespoons++;
                    }
                }
                if (fmod(a,0.0208333) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0208333;
                        teaspoons++;
                    }
                }
            }

            // If below 1/4 cup, remaining amount will be divided between
            // whatever tablespoons and teaspoons remain.
            else if (a < .25) {
                if (a >= 0.0625 && fmod(a,0.0625) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0625;
                        tablespoons++;
                    }
                }
                if (fmod(a,0.0208333) < 0.0208333) {
                    while (a > 0) {
                        a -= 0.0208333;
                        teaspoons++;
                    }
                }
            }

            return 0;
        }
};

float convertToCups(float original, int type)
{
    float cups = 0;

    if (type == 1)
    {
        cups = original;
    }
    else if (type == 2)
    {
        cups = original / 2;
    }
    else if (type == 3)
    {
        cups = original / 3;
    }
    else if (type == 4)
    {
        cups = original / 4;
    }
    else if (type == 5)
    {
        cups = original / 16;
    }
    else if (type == 6)
    {
        cups = original / 48;
    }

    return cups;
}

int main()
{
    Recipe recipe;
    Simplify simplify;

    // cout << simplify.quarterCups << endl;

    int type = recipe.getType();

    float multiplier = recipe.newServings / recipe.oldServings;

    float newMeasurement = recipe.measurement * multiplier;

    float newCups = convertToCups(newMeasurement, type);

    simplify.simplifyMeasurement(newCups);

    cout << "The new recipe is " << newCups << " cups of " << recipe.ingredient << endl;

    cout << endl << "Or" << endl << endl;

    cout << "Add " << simplify.cups << " cups," << endl;
    cout << "Add " << simplify.halfCups << " half-cups," << endl;
    cout << "Add " << simplify.thirdCups << " third-cups," << endl;
    cout << "Add " << simplify.quarterCups << " quarter-cups," << endl;
    cout << "Add " << simplify.tablespoons << " tablespoons," << endl;
    cout << "Add " << simplify.teaspoons << " teaspoons of " << recipe.ingredient << endl;

    return 0;
}