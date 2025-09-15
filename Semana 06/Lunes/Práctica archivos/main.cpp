#include <iostream>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include "clsArchivoCiudades.h"
#include "clsArchivoPaises.h"

/**
1 - Agregar una funci�n global que busque un registro de pa�s a partir de su c�digo.
La funci�n debe poder devolver si el registro existe o no.

2 - Agregar una funci�n global que permita agregar un registro de Pa�s al archivo de pa�ses.

3 - Agregar una funci�n global que permita listar todos los pa�ses del archivo de pa�ses.

4 - Agregar una funci�n global que permita listar todos las ciudades y su poblaci�n que pertenezcan
a un pa�s cuyo c�digo se ingresa previamente por teclado. Mostrar la capital del pa�s, si se tiene registro
de ella, al final de todo. Un valor 0 en el campo _capital indica que la misma no fue cargada.

5 - Agregar una funci�n global que permita listar todos los pa�ses con su nombre y superficie.
Adem�s, indicar qu� porcentaje representa esa superficie sobre el total mundial.
El total mundial surge de la suma de las superficies de cada pais.

6 - Agregar una funci�n global que permita listar todas las ciudades en orden alfab�tico.

7 - Listar los paises cuya poblaci�n total supere la poblaci�n media entre todos los paises.

NOTA: Elaborar un men� que permita ejecutar cada uno de los puntos.

*/

int main()
{
    cout<<fixed;
    ArchivoCiudades arc;
    arc.listarRegistros();
    return 0;
}
