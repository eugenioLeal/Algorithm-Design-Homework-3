// O(n^3)
#include <bits/stdc++.h>
using namespace std;
// Number of Men or Women
#define N  4

// This function returns true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    // Check if w prefers m over her current engagment m1
    for (int i = 0; i < N; i++)
    {
        // If m1 comes before m in lisr of w, then w prefers her
        // cirrent engagement, don't do anything
        if (prefer[w][i] == m1)
            return true;

        // If m cmes before m1 in w's list, then free her current
        // engagement and engage her with m
        if (prefer[w][i] == m)
           return false;
    }
}

// Prints stable matching for N boys and N girls. Boys are numbered as 0 to
// N-1. Girls are numbereed as N to 2N-1.
void stableMarriage(int prefer[2*N][N])
{
    // Stores partner of women. This is our output array that
    // stores paing information.  The value of wPartner[i]
    // indicates the partner assigned to woman N+i.  Note that
    // the woman numbers between N and 2*N-1. The value -1
    // indicates that (N+i)'th woman is free
    int wPartner[N];

    // An array to store availability of men.  If mFree[i] is
    // false, then man 'i' is free, otherwise engaged.
    bool mFree[N];

    // Initialize all men and women as free
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    // While there are free men
    while (freeCount > 0)
    {
        // Pick the first free man (we could pick any)
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;

        // One by one go to all women according to m's preferences.
        // Here m is the picked free man
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];

            // The woman of preference is free, w and m become
            // partners (Note that the partnership maybe changed
            // later). So we can say they are engaged not married
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else  // If w is not free
            {
                // Find current engagement of w
                int m1 = wPartner[w-N];

                // If w prefers m over her current engagement m1,
                // then break the engagement between w and m1 and
                // engage m with w.
                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } // End of Else
        } // End of the for loop that goes to all women in m's list
    } // End of main while loop


    // Print the solution
    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << wPartner[i] << endl;
}

// Driver program to test above functions
int main()
{
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(prefer);

    return 0;
}

/*
LAS PAREJAS ESTABLES
Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen las
preferencias de los unos por los otros. Más concretamente, la fila M[i,·] es una
ordenación (de mayor a menor) de las mujeres según las preferencias del i-ésimo
hombre y, análogamente, la fila H[i,·] es una ordenación (de mayor a menor) de los
hombres según las preferencias de la i-ésima mujer.

Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y
mujeres tal que todas las parejas formadas sean estables. Una pareja (h,m) es
estable si no se da ninguna de estas dos circunstancias:

Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere
sobre la mujer m y además la mujer m’ también prefiere a h sobre h’.
Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m lo prefiere
sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”.

THE STABLE COUPLES
Suppose we have n males and n females and two M and H matrices that contain
preferences for each other. More precisely, the row M [i, ·] is a
ordering (from highest to lowest) of women according to the preferences of the ith
man, and, similarly, the row H [i, ·] is an ordering (from major to minor) of the
men according to the preferences of the i-th woman.

Design an algorithm that finds, if any, a pairing of men and
women so that all couples formed are stable. A couple (h, m) is
stable if neither of the above circumstances exists:

There is a woman m '(which forms the pair (h', m ')) such that man h prefers it
on the woman m and besides the woman m 'also prefers to h on h'.
There is a man h "(which forms the pair (h", m ")) such that woman m prefers it
on the man h and in addition the man h "also prefers to m on the woman m".
*/
