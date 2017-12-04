
/**
 * Genera menu y permite ingresar una opcion
 * \param texto[] char array de caracters con los qué se genera el menu
 * \return char la opcion ingresada por el usuario
 *
 */
char mostrarMenu(char texto[]);

/** \brief
 * Pausa la pantalla y luego la limpia
 * \return void
 *
 */
void borrarPantalla();

/**
 * Chequea que el dato ingresado sea solo numeros positivos enteros
 * \param num[] char variable donde se guardan los datos
 * \return int -1 si no esta compuesto de numeros positivos o 0 si son numeros positivos
 *
 */
int chequeoNumero(char num[]);

/**
 *  Chequea que el dato ingresado sea solo numeros positivos enteros
 * \param num[] char variable donde se guardan los datos
 * \return int 1 si no son numeros enteros o flotantes o caracteres y 0 si son numeros
 *
 */
int chequeoFloat(char num[]);

/** \brief
 *  Se reserva en memoria un char de dimencion dinamica
 * \param buffer[] char cadena de caracteres ingresada
 * \return void* Retorna (NULL) si hay error o el puntero a donde se almaceno la cadena de caracteres
 *
 */
char* charDyn(char buffer[] );


