/*==============================================================================================================//
* SUB - HST UTILITA																								//
* --------------------------------------------------------------------------------------------------------------//
* AUTORE: Halley Informatica																					//
*		  Ticau Vasile																							//
* --------------------------------------------------------------------------------------------------------------//
* FUNZIONI SVOLTE: - Funzioni di supporto per la libreria WPRI													//
* --------------------------------------------------------------------------------------------------------------//
* TIPOLOGIA: UTILITA																							//
* LIBRERIE:																										//
*       PDFNetC		- Libreria per lavorare con le PDF															//
* REVISIONI:																									//
* BUGS CONOSCIUTI:																								//
* ==============================================================================================================*/
/*----- INCLUDE DIVISION  --------------------------------------------------------------------------------------*/
#include "hst_utilita.h"
#include "hc_header.h"
//----- Standard -----------------------------------------------------------------------------------------------//
#include <algorithm>																							// Per sort, reverse... vector
//----- Stream -------------------------------------------------------------------------------------------------//
#include <sys/stat.h>
#include <sstream>																								// Pentru lucrul cu 'stringstream'
#include <fstream>																								// Pentru lucrul cu 'ifstream/ofstream'
//----- Time ---------------------------------------------------------------------------------------------------//
#include <time.h>																								// Pentru accesarea structurii TM

#ifdef __linux
#include <unistd.h>
#include <sys/resource.h>
#else
#include "windows.h"
#include <psapi.h>
#endif

//----- VARIABILI GLOBALI --------------------------------------------------------------------------------------//
static short _logLevel; 																						// Nivelul de LOG

#ifndef __GNUC__
#pragma region FUNZIONI DI UTILITA
#endif 


//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE GetRGBFromStr (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Estrae i valori di ogni colore del modello RGB da una stringa								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  str        string        (I)  : stringa da analizzare														//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Valore decimale del colore																		//
//--------------------------------------------------------------------------------------------------------------// 
double GetRGBFromStr(string str) {																				// Dichiarazione di funzione 
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char* p;																									// 
	//==========================================================================================================//
	long l = strtol(str.c_str(), &p, 16);																		//
	/*----- Final ----------------------------------------------------------------------------------------------*/
	return(l / (double)255);																					// 
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ClearExtendASCII (non esportata)																	//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Sostituisce i caratteri ASCII estesi con il simbolo "_"										//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  str        string        (I/O)  : stringa da analizzare														//
//--------------------------------------------------------------------------------------------------------------//
void ClearExtendASCII(string& str) {																			// Dichiarazione di funzione
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	int i = 0;																									// Counter de pozitie
	//==========================================================================================================//
	while (str[i]) {																							// Parcurge sirul de caracter, caracter cu caracter
		if (!isascii(str[i])) str[i] = '_';																		// Daca caracterul de pe pozitia curenta este ASCII, inlocuiestel cu '_'
		i++;																									// Incrementeaza pozitia
	}
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE CheckPathByFinalSlash (non esportata)																//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Controlla il percorso per vedere se contiene o no una barra alla fine						//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  path        string        (I/O)  : percorso da analizzare													//
//--------------------------------------------------------------------------------------------------------------// 
void CheckPathByFinalSlash(string& path) {																		// Dichiarazione di funzione 
	// Controllo se c'e' lo H_TREE finale 
	size_t index = path.find_last_of(H_TREE);																	// Extrage pozitia ultimului H_TREE in sir
	if (index != (path.size() - 1)) path += H_TREE;																// Daca nu este identificat H_TREE in sir, adauga la final H_TREE
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ConvIntToStr (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Convert int to string, base 10																//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  x        int        (I)  : the int for conversion															//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO:																										//
//					string - result of conversion in char* forma												//
//--------------------------------------------------------------------------------------------------------------// 
string ConvIntToStr(int x) {																					//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char strBuff[20];																							// Buffer string
	//================================================================================================= end ====//
	SPRINTF(strBuff, "%d", x);																					// Executa practic conversia NUMAR->STRING
	return std::string(strBuff);																				// Returneaza STRNG-ul obtinut
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ResizeImg (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Calcola la dimensione dell'immagine per adattarla al campo									//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  fldWidth         double        (I)      : larghezza del campo												//
//  fldHeight        double        (I)      : altezza del campo													//
//  xoff             double        (I/O)    : posizione orizzontale dell'immagine nella pagina					//
//  yoff             double        (I/O)    : posizione verticale dell'immagine nella pagina					//
//  imgWidth         double        (I/O)    : larghezza dell'immagine											//
//  imgHeight        double        (I/O)    : altezza dell'immagine												//
//  imgFit           bool          (I)      : flag che specifica se l'immagine riempira il campo o no			//
//--------------------------------------------------------------------------------------------------------------// 
void ResizeImg(double fldWidth, double fldHeight, double& xoff, double& yoff, double& imgWidth, double& imgHeight, bool imgFit) {// Dichiarazione di funzione
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	double scaleFactor = 1.0;
	//==========================================================================================================//
	if (imgFit) {																								// Daca ESTE specificata umplerea campului cu imaginea
		imgHeight -= (imgHeight - fldHeight);																	// Recalculeaza inaltimea imaginii
		imgWidth -= (imgWidth - fldWidth);																		// Recalculeaza latimea imaginii
		return;																									// paraseste functia
	}

	if ((imgHeight == fldHeight) && (imgWidth == fldWidth))														// Daca inaltimea si latimea imaginii corespunde cu inaltimea si latimea campului
		return;																									// paraseste functia
	if ((imgHeight == fldHeight) && (imgWidth < fldWidth)) {													// Daca inaltimea imaginii corespunde cu inaltimea campului, iar latimea imaginii este mai mica ca latimea campului
		xoff += (fldWidth - imgWidth) / 2;																		// Pozitioneaza imaginea la mijlocul campului
		return;																									// paraseste functia
	}
	if ((imgHeight <= fldHeight) && (imgWidth > fldWidth)) {													// Daca inaltimea imaginii este mai mica sau egala cu inaltimea campului, iar latimea imaginii este mai mare ca latimea campului
		scaleFactor = (double)fldWidth / (double)imgWidth;														// Calculeaza factorul de redimensionare din raportul latimii campului la latimea imaginii
		imgHeight *= scaleFactor;																				// Recalculeaza inaltimea imaginii
		imgWidth *= scaleFactor;																				// Recalculeaza latimea imaginii
		yoff += (fldHeight - imgHeight) / 2;																	// Pozitioneaza imaginea la mijlocul campului
		return;																									// paraseste functia
	}
	if ((imgHeight < fldHeight) && (imgWidth == fldWidth)) {													// Daca inaltimea imaginii este mai mica ca inaltimea campului si latimea imaginii este egala cu latimea campului
		yoff += (fldHeight - imgHeight) / 2;																	// Pozitioneaza imaginea la centrul campului
		return;																									// paraseste functia
	}
	if ((imgHeight > fldHeight) && (imgWidth <= fldWidth)) {													// Daca inaltimea imaginii este mai mare ca inaltimea campului, iar latimea imaginii este mai mica sau egala cu latimea campului
		scaleFactor = (double)fldHeight / (double)imgHeight;													// Calculeaza factorul de redimensionare din raportul inaltimii campului la inaltimea imaginii
		imgHeight *= scaleFactor;																				// Recalculeaza inaltimea imaginii
		imgWidth *= scaleFactor;																				// Recalculeaza latimea imaginii
		xoff += (fldWidth - imgWidth) / 2;																		// Pozitioneaza imaginea la centrul campului
		return;																									// paraseste functia
	}
	if ((imgHeight != fldHeight) && (imgWidth != fldWidth)) {													// Daca inaltimea imaginii este diferita de inaltimea campului si latimea imaginii estediferita de latimea campului
		double scaleFH = (double)fldHeight / (double)imgHeight;													// Calculeaza factorul de redimensionare din raportul inaltimii campului la inaltimea imaginii
		double scaleFW = (double)fldWidth / (double)imgWidth;													// Calculeaza factorul de redimensionare din raportul latimii campului la latimea imaginii
		scaleFactor = (scaleFH < scaleFW) ? scaleFH : scaleFW;													// Preia factorul care este mai mic
		imgHeight *= scaleFactor;																				// Recalculeaza inaltimea imaginii
		imgWidth *= scaleFactor;																				// Recalculeaza latimea imaginii
		// Se vor implementa ambele 
		yoff += (fldHeight - imgHeight) / 2;																	// Pozitioneaza imaginea la mijlocul campului
		xoff += (fldWidth - imgWidth) / 2;																		// Pozitioneaza imaginea la centrul campului
		return;																									// paraseste functia
	}
	return;																										// paraseste functia
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ScaleCalc (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Calcola la sclala di ridimensionamento di un'immagine in base alle dimesioni del contenitore//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  rectWidth        double        (I)  : larghezza del contenitore												//
//  rectHeight       double        (I)  : altezza del contenitore												//
//  imgWidth         double        (I)  : larghezza dell'immagine												//
//  imgHeight        double        (I)  : altezza dell'immagine													//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Valore decimale della scala																		//
//--------------------------------------------------------------------------------------------------------------// 
double ScaleCalc(double rectWidth, double rectHeight, double imgWidth, double imgHeight) {						// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	double  scale = 1;																							//
	double xscale = 0.0;																						//
	double yscale = 0.0;																						//

	double xdiff = rectWidth - imgWidth;																		// 
	double ydiff = rectHeight - imgHeight;																		//
	//==========================================================================================================//
	if (xdiff < 0)																								//
		xscale = imgWidth / rectWidth;																			//
	if (ydiff < 0)																								//
		yscale = imgHeight / rectHeight;																		//

	if ((xscale == 0) && (yscale == 0))																			//
		scale = 1.0;																							//
	else																										//
		if (xscale < yscale)																					//
			scale = xscale;																						//
		else																									//
			scale = yscale;																						//
	return scale;																								//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE MmToPixel (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Trasforma la lunghezza da MM a PIXEL.														//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  len        double        (I)  : lunghezza in MM da transformare												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Lunghezza in PIXEL																				//
//--------------------------------------------------------------------------------------------------------------// 
double MmToPixel(double len) {																					// Dichiarazione di funzione 
	return(len * 3.779527559);																					//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE PixelToMm (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Trasforma la lunghezza da PIXEL a MM.														//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  len        double        (I)  : lunghezza in PIXEL da transformare											//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Lunghezza in MM																					//
//--------------------------------------------------------------------------------------------------------------// 
double PixelToMm(double len) {																					// Dichiarazione di funzione 
	return(len / 3.779527559);																					//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE MmToPoint (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Trasforma la lunghezza da MM a POINT.														//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  len        double        (I)  : lunghezza in MM da transformare												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Lunghezza in POINT																				//
//--------------------------------------------------------------------------------------------------------------// 
double MmToPoint(double len) {																					// Dichiarazione di funzione 
	return(len * 2.834645669);																					//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE PointToMm (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Trasforma la lunghezza da POINT a MM.														//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  len        double        (I)  : lunghezza in POINT da transformare											//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Lunghezza in MM																					//
//--------------------------------------------------------------------------------------------------------------// 
double PointToMm(double len) {																					// Dichiarazione di funzione 
	return(len / 2.834645669);																					// 
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE CreateFullFontPath (non esportata)																	//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Crea il percorso completo del font															//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  fontName    string        (I)  : Il nome del font (Es. ARIAL)												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Il percorso completo del font																		//
//--------------------------------------------------------------------------------------------------------------// 
string CreateFullFontPath(string fontName) {																	// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	string ret;																									//
	char   remotePath[256], systemPath[256];																	//
	//==========================================================================================================//
	if (GetEnvHH((char*)"SY")) {		                                                                        // Daca s-a obtinut path-ul catre SY
		strcpy(systemPath, fontName.c_str());																	// Stocheaza numele FONT-ului
		PathBuild(systemPath, 0, remotePath);																	// Contruieste path-ul complet pe server
		ret = systemPath;																						// Stocheaza path-ul de system pentru RETURN
	}																											//
	else {																										//
#ifdef WIN32
		ret = "c:\\windows\\fonts\\";																			// Indica path-ul folderului de fonturi pe system
#else
		ret = "/u/ghx/fonts/";																					// Indica path-ul folderului de fonturi pe system
#endif
		ret += fontName.substr(9, fontName.size() - 9).c_str();													// Adauga numele fontului cautat
	}																											//
	return ret;																									// Returneaza path-ul absolut catre FONT
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE GetPathPartFromFilePath (non esportata)																//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Estrai parti del percorso dal percorso del file												//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   filePath    char*        (I)  : Il percorso del file														//
//   parte       int          (I)  : indica la parte da estrarre												//
//                                    1        - Percorso + Nome file + "."										//
//                                    2        - Nome file														//
//                                    3        - Estensione del file											//
//                                    default - Percorso + "H_TREE"												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    La parte indicata del percorso																	//
//--------------------------------------------------------------------------------------------------------------// 
string GetPathPartFromFilePath(char* filePath, int parte) {														// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	string ret = "";																							//
	string app = "";																							//
	size_t pos = 0, pos_slash = 0;																				//
	//==========================================================================================================//
	if (filePath) {																								//
		app.append(filePath);																					//
		switch (parte) {																						//
		case 1: {																								// Return: Path + Filename + "."
			pos = app.find_last_of(".");																		//
			if (pos != string::npos)																			//
				ret = app.substr(0, pos + 1);																	//
		}break;																									//
		case 2: {																								// Return: Filename
			pos_slash = app.find_last_of(H_TREE);																//
			if (pos_slash != string::npos)																		//
				app = app.substr(pos_slash + 1);																//
			pos = app.find_last_of(".");																		//
			if (pos != string::npos)																			//
				ret = app.substr(0, pos);																		//
		}break;																									//
		case 3: {																								// Return: Extension
			pos = app.find_last_of(".");																		//
			if (pos != string::npos)																			//
				ret = app.substr(pos + 1);																		//
		}break;																									//
		default: {																								// Return: Path + "\"
			pos_slash = app.find_last_of(H_TREE);																//
			if (pos_slash != string::npos)																		//
				ret = app.substr(0, pos_slash + 1);																//
		}break;																									//
		}																										//
	}																											//
	return ret;																									//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ConvAlignStrToInt (non esportata)																	//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Converte l'allineamento specificato nella stringa nel tipo INT								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   alignStr    char*        (I)  : La stringa con l'allineamento												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Uno dei valori specificati nell'enumerazione TestoAlliniamento									//
//--------------------------------------------------------------------------------------------------------------// 
int ConvAlignStrToInt(string alignStr) {																		// Dichiarazione di funzione 
	/* Testo scrito Orizontale */																				//
	if (alignStr.compare("SA") == 0)																			//
		return all_SinistraAlto;																				//
	if (alignStr.compare("CA") == 0)																			//
		return all_CentroAlto;																					//
	if (alignStr.compare("DA") == 0)																			//
		return all_DestraAlto;																					//
	if (alignStr.compare("GA") == 0)																			//
		return all_GiustificaAlto;																				//

	if (alignStr.compare("SM") == 0 || alignStr.compare("OS") == 0)												//
		return all_SinistraMezzo;																				//
	if (alignStr.compare("CM") == 0 || alignStr.compare("OC") == 0)												//
		return all_CentroMezzo;																					//
	if (alignStr.compare("DM") == 0 || alignStr.compare("OD") == 0)												//
		return all_DestraMezzo;																					//
	if (alignStr.compare("GM") == 0 || alignStr.compare("OG") == 0)												//
		return all_GiustificaMezzo;																				//

	if (alignStr.compare("SB") == 0)																			//
		return all_SinistraBasso;																				//
	if (alignStr.compare("CB") == 0)																			//
		return all_CentroBasso;																					//
	if (alignStr.compare("DB") == 0)																			//
		return all_DestraBasso;																					//
	if (alignStr.compare("GB") == 0)																			//
		return all_GiustificaBasso;																				//

	/* Testo scrito Verticale */																				//
	if (alignStr.compare("AS") == 0)																			//
		return all_AltoSinistra;																				//
	if (alignStr.compare("AC") == 0 || alignStr.compare("VA") == 0)												//
		return all_AltoCentro;																					//
	if (alignStr.compare("AD") == 0)																			//
		return all_AltoDestra;																					//
	if (alignStr.compare("AG") == 0)																			//
		return all_AltoGiustifica;																				//

	if (alignStr.compare("MS") == 0)																			//
		return all_MezzoSinistra;																				//
	if (alignStr.compare("MC") == 0 || alignStr.compare("VC") == 0)												//
		return all_MezzoCentro;																					//
	if (alignStr.compare("MD") == 0)																			//
		return all_MezzoDestra;																					//
	if (alignStr.compare("MG") == 0 || alignStr.compare("VG") == 0)												//
		return all_MezzoGiustifica;																				//

	if (alignStr.compare("BS") == 0)																			//
		return all_BassoSinistra;																				//
	if (alignStr.compare("BC") == 0 || alignStr.compare("VB") == 0)												//
		return all_BassoCentro;																					//
	if (alignStr.compare("BD") == 0)																			//
		return all_BassoDestra;																					//
	if (alignStr.compare("BG") == 0)																			//
		return all_BassoGiustifica;																				//

	/* Nessun allineamento specificato */																		//
	else																										//
		return all_SinistraMezzo;																				//

	return 0;																									//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE GetEnvHH (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Lettura variabili di environment															//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   name    char*        (I)  : il nome della variabile d'ambiente (Es. "TMP")									//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Il valore mascherato dalla variabile (Es. "C:/tmp" o "\usr\tmp")									//
//--------------------------------------------------------------------------------------------------------------// 
char* GetEnvHH(char* name) {																					// Dichiarazione di funzione 
	return(h_getenv(name));																						// Returneaza valoarea variabilei din AMBIENTE
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ToUpperCase (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Trasforma in maiuscolo una stringa.															//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   str        char*        (I/O)  : stringa da trasformare													//
//--------------------------------------------------------------------------------------------------------------// 
void ToUpperCase(char* str) {																					// Dichiarazione di funzione 
	for (; *str; str++) *str = toupper(*str);																	//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ToLowerCase (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Trasforma in minuscolo una stringa.															//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   str        string        (I/O)  : stringa da trasformare													//
//--------------------------------------------------------------------------------------------------------------// 
void ToLowerCase(string& str) {																					// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	int i = 0;																									// Contor
	//==========================================================================================================//
	while (str[i]) {																							//
		str[i] = tolower(str[i]);																				//
		i++;																									//
	}																											//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SlashToBackslash (non esportata)																	//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Converte le barre dritte in barre rovesciate.												//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   path		char*        (I/O)  : Percorso di file															//
//   len        int            (I)    : Lunghezza dell percorso													//
//--------------------------------------------------------------------------------------------------------------// 
void SlashToBackslash(char* path, int len) {																	// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	char* p;																									//
	//==========================================================================================================//
	while ((p = (char*)memchr(path, '/', len)) != NULL) *p = '\\';												//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE BackslashToSlash (non esportata)																	//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Converte le barre rovesciate in barre dritte.												//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   path		char*        (I/O)  : Percorso di file															//
//   len        int            (I)    : Lunghezza dell percorso													//
//--------------------------------------------------------------------------------------------------------------// 
void BackslashToSlash(char* path, int len) {																	// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	char* p;																									//
	//==========================================================================================================//
	while ((p = (char*)memchr(path, '\\', len)) != NULL) *p = '/';												//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE IsPartOfStr (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Ricerca una stringa in un'altra stringa principale											//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   initStr        int      (I)  : offset di inizio ricerca su stringa principale								//
//   str            char*    (I)  : stringa su cui effettuare la ricerca.										//
//   lStr           int      (I)  : lunghezza stringa 'str'														//
//   findStr        char*    (I)  : stringa da ricercare.														//
//   lFindStr       int      (I)  : lunghezza stringa 'lFindStr'												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO																										//
//                 -1 : stringa non trovata nella stringa principale											//
//                pos : posizione della stringa 'findStr' all'interno di quella principale.						//
//--------------------------------------------------------------------------------------------------------------// 
int IsPartOfStr(int initStr, char* str, int lStr, char* findStr, int lFindStr) {								// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	char* pos, * posMax;																						// 
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	if (initStr > lStr) return(-1);																				//
	if (initStr < 0) initStr = 0;																				//
	//==========================================================================================================//
	posMax = str + lStr - lFindStr;																				// Posizione vietata    
	for (pos = str + initStr; (pos <= posMax) && ((pos = (char*)memchr(pos, *findStr, (posMax - pos) + 1)) != NULL)//
		&& (lFindStr > 1) && memcmp(pos, findStr, lFindStr); pos++);											//
	return (int)((pos == NULL || pos > posMax) ? -1 : pos - str);												// Posizione relativa
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE PathBuild (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Costruisce un path del file da assign (DEV:NOME.EXT) e tipo esensione.						//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   filePath        char*        (I/O)  : il percorso del file													//
//   typeOfDefExt    char*        (I)  : tipo estensione di default.											//
//   remoteSrvName   char*        (O)  : per ritornare nome server remoto										//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO																										//
//                 0 : assign normale																			//
//                 1 : si tratta di 'TT:'.																		//
//                 2 : device speciale (PRN, COM1 ecc.)															//
//--------------------------------------------------------------------------------------------------------------// 
int PathBuild(char* filePath, char typeOfDefExt, char* remoteSrvName) {											// Dichiarazione di funzione 
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	char appo[256], defExt[4], remotoSrv = 0;																	//
	char* dev, * nam, * ext;																					//
	int i, j;// , n;																							//
	//==========================================================================================================//
	if (remoteSrvName) remoteSrvName[0] = '\0';																	//

	if ((dev = strchr(filePath, '!')) != NULL) {																// controlla se e' un nome remoto
		i = (int)(dev - filePath);																				//
		filePath[i] = '\0';																						//
		if (remoteSrvName)																						// copia su remote_name il nome
			strcpy(remoteSrvName, filePath);																	// del server remoto
		filePath[i] = '!';																						//
		i++;																									//
		j = i;																									//
		remotoSrv = 1;																							//
		if (strchr(filePath + j, '!') != NULL) {																// se c'e' altro nome remoto
			i = (int)strlen(filePath + j);																		// ritorna senza fare altre
			memmove(filePath, filePath + j, i + 1);																// analisi sull'assign
			return(0);																							//
		}																										//
	}																											//
	else j = 0;																									//

	nam = ext = dev = NULL;																						// Copio nome file compattando blank
	for (i = 0; filePath[j]; j++) switch (filePath[j]) {														//
	case ' ':																									// Blank ignorati
		break;																									//
	case ':':
		if (dev == NULL && i > 1) {																				//
			dev = nam;																							//
			appo[i++] = '\0';																					//
			nam = NULL;																							//
		}																										//
		else appo[i++] = filePath[j];																			//
		break;																									//
	case '$':
		if (dev == NULL) {																						//
			dev = appo + i;																						//
			for (++j; filePath[j] && isalnum(filePath[j]); j++) appo[i++] = filePath[j];						//
			appo[i++] = '\0'; nam = NULL;																		//
		}																										//
		else appo[i++] = filePath[j];																			//
		break;																									//
	// Scafi 18-06-2018: tolto in quanto le [] sui nomi file sono caratteri accettabili e nessuno sa a cosa servisse questa cosa 
	//case '[':
	//	if ((n = IsPartOfStr(j, filePath, (int)strlen(filePath), (char*)"]", 1)) > j) {							//
	//		j = n;																								//
	//		break;																								//
	//	}																										//
	default:
		if (nam == NULL) nam = appo + i;																		//
		appo[i++] = filePath[j];																				//
		break;																									//
	}																											//
	appo[i] = '\0';																								// Tappo
	if (nam && !*nam)nam = NULL;																				// Se stringa vuota, non c'e' nam
	if (nam != NULL) {																							// Nome file non nullo
		ext = appo + i - 1;																						// Punto alla fine stringa nome
		i = (int)(appo + i - nam);																				// Lunghezza stringa nome
		/*----------------------------------------------------------------------*/								//
		/* Modificato il 22/4/97 per prendere l'estensione anche se maggiore    */								//
		/* di tre caratteri; il controllo sulle barre serve nel caso in cui ci     */							//
		/* sia una directory che contiene il '.' sul nome (non si puo' usare    */								//
		/* isalnum() altrimenti non si potrebbero mettere i caratteri tipo '_'    */							//
		/* sull'estensione).                                                    */								//
		/*  for(j = (i>3)? 3:i; j && isalnum(*ext) && (ext > nam); j--, ext--);    */							//
		/*  for(j = (i>3)? 3:i; j && (*ext != '.') && (ext > nam); j--, ext--);    */							//
		/*----------------------------------------------------------------------*/								//
		for (j = i; j && (*ext != '.') && (*ext != '/') && (*ext != '\\')										//
			&& (ext > nam); j--, ext--);																		//
		if (*ext != '.') ext = NULL;																			//
		else { *ext = '\0'; ext++; }																			// Break nome da estensione
	}																											//
	*filePath = '\0';																							// Ricostruisco stringa nomefile
	if (dev != NULL) {																							//
		if (strcmp(dev, "TT") == 0 || strcmp(dev, "tt") == 0) {													//
			strcpy(filePath, dev); return(1);																	//
		}																										// Trattamento speciale TT:
		if ((dev = GetEnvHH(dev)) != NULL) {																	//
			strcat(filePath, dev);																				// Get nome device da environment
			i = (int)strlen(filePath);																			// Controllo se aggiungere /
			if (nam != NULL && filePath[i - 1] != H_TREE && *nam != H_TREE)										//
			{																									//
				filePath[i++] = H_TREE; filePath[i] = '\0';														//
			}																									//
		}																										//
	}																											//
	if (dev == NULL) {																							//
		/*----------------------------------------------------------------------*/								//
		/* 11/9/97: ora effettua il controllo per la presenza delle barre con     */							//
		/* entrambi i tipi, per evitare che se viene passato un nome con le        */							//
		/* barre di tipo diverso da H_TREE, venga messo davanti al nome il         */							//
		/* percorso della directory corrente                                    */								//
		/*----------------------------------------------------------------------*/								//
		if (nam != NULL && strchr(nam, '\\') == NULL && strchr(nam, '/') == NULL &&								//
			strchr(nam, '!') == NULL && !remotoSrv) {															//
			GETCWD(filePath, 50);																				// legge directory corrente
			i = (int)strlen(filePath);																			// Controllo se aggiungere /
			if (nam != NULL && filePath[i - 1] != H_TREE) {														//
				filePath[i++] = H_TREE;																			//
				filePath[i] = '\0';																				//
			}																									//
		}																										//
	}																											//
	if (nam != NULL) strcat(filePath, nam);																		// Cateno il nomefile
	if (typeOfDefExt != F_ISM) {																				// Aggiungo estensione se non ISAM
		if (ext == NULL) {																						//
			if (nam != NULL || dev == NULL) {																	//
				strcpy(defExt, H_FEXT[typeOfDefExt]);															// Load estensione di default
				for (i = (int)strlen(filePath) - 1; i >= 0 && isdigit(filePath[i]); i--);						//
				if (i >= 0 && isupper(filePath[i])) ToUpperCase(defExt);										//
				strcat(filePath, ".");																			// Aggiunge punto
				strcat(filePath, defExt);																		// Aggiunge estensione
			}																									//
		}																										//
		else {																									//
			if (*ext) { strcat(filePath, "."); strcat(filePath, ext); }											//
		}																										//
	}																											//
	if ((dev = strchr(filePath, '!')) != NULL) {																// controlla se e' un nome remoto
		i = (int)(dev - filePath);																				//
		filePath[i] = '\0';																						//
		if (remoteSrvName)																						// copia su remote_name il nome
			strcpy(remoteSrvName, filePath);																	// del server remoto
		i++;																									//
		j = (int)strlen(filePath + i) + 1;																		//
		memmove(filePath, filePath + i, j);																		//
		if (ext && !*ext) strcat(filePath, ".");																// aggiunge "." se senza estensione
	}																											//
	else {																										// converte le barre sul nome
		if (remotoSrv) {																						//
			if (ext && !*ext) strcat(filePath, ".");															// aggiunge "." se senza estensione
		}																										//
		else																									//
			//#ifdef DOSLIKE
#ifdef WIN32
			SlashToBackslash(filePath, (int)strlen(filePath));													// da dritte a rovesciate (per DOS)
#else
			BackslashToSlash(filePath, strlen(filePath));														// da rovesciate a dritte (per UNIX)
#endif
	}																											//
	return(0);																									//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SetPdfAConformanceLevel (non esportata)																//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Impostare il livello di conformita PDF/A dal tipo specificato dall'utente per conversione	//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   userType    char*                            (I)  : Tipo specificato dall'utente							//
//   pdfaLevel   PDFACompliance::Conformance      (O)  : Livello di conformita PDF/A							//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO		errore: 1 -	un tipo errato		| 0 - OK														//
//--------------------------------------------------------------------------------------------------------------//
int SetPdfAConformanceLevel(char* userType, PDFACompliance::Conformance* pdfaLevel) {							// Dichiarazione di funzione
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	WriteLogMessage(__FUNCTION__, "Il livello di conformita PDF/A deve essere impostato a: ", userType);		// Scrie LOG
	if (!strlen(userType))																						// Se il tipo di conversione PDF/A e mancante o NULL
		strcpy(userType, "1B");																					// Quindi prende il valore predefinito ('1B')
	//==========================================================================================================//
	if (!strcmp(userType, "1A") || !strcmp(userType, "1a"))														// Se il tipo di conversione PDF/A e '1A'
		*pdfaLevel = PDFACompliance::e_Level1A;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 1A 
	else if (!strcmp(userType, "1B") || !strcmp(userType, "1b"))												// Se il tipo di conversione PDF/A e '1B' 
		*pdfaLevel = PDFACompliance::e_Level1B;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 1B
	else if (!strcmp(userType, "2A") || !strcmp(userType, "2a"))												// Se il tipo di conversione PDF/A e '2A' 
		*pdfaLevel = PDFACompliance::e_Level2A;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 2A 
	else if (!strcmp(userType, "2B") || !strcmp(userType, "2b"))												// Se il tipo di conversione PDF/A e '2B' 
		*pdfaLevel = PDFACompliance::e_Level2B;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 2B 
	else if (!strcmp(userType, "2U") || !strcmp(userType, "2u"))												// Se il tipo di conversione PDF/A e '2U' 
		*pdfaLevel = PDFACompliance::e_Level2U;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 2U 
	else if (!strcmp(userType, "3A") || !strcmp(userType, "3a"))												// Se il tipo di conversione PDF/A e '3A' 
		*pdfaLevel = PDFACompliance::e_Level3A;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 3A 
	else if (!strcmp(userType, "3B") || !strcmp(userType, "3b"))												// Se il tipo di conversione PDF/A e '3B' 
		*pdfaLevel = PDFACompliance::e_Level3B;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 3B 
	else if (!strcmp(userType, "3U") || !strcmp(userType, "3u"))												// Se il tipo di conversione PDF/A e '3U' 
		*pdfaLevel = PDFACompliance::e_Level3U;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 3U 
	else if (!strcmp(userType, "NO") || !strcmp(userType, "no"))												// Se il tipo di conversione PDF/A e 'NO' 
		*pdfaLevel = PDFACompliance::e_NoConformance;															// Inizializza il tipo di output con il livello di conformita PDF/A: NoConformance (solo compatibilita)
	else																										// Se il tipo di conversione PDF/A non e uno dei precedenti 
		return 1;																								// Restituisce l'errore: un tipo errato
	WriteLogMessage(__FUNCTION__, "Il livello di conformita PDF/A e stato impostato", userType);				// Scrie LOG
	return 0;																									// Restituisce l'errore: OK
}

//--------------------------------------------------------------------------------------------------------------//
// FUNZIONE SetPdfAConformanceLevelSalva (non esportata)														//
// -------------------------------------------------------------------------------------------------------------//
// FUNZIONI SVOLTE: Impostare il livello di conformita PDF/A dal tipo specificato dall'utente per salvare		//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   userType    string                           (I)  : Tipo specificato dall'utente							//
//   pdfaLevel   PDFACompliance::Conformance      (O)  : Livello di conformita PDF/A							//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO		errore: 1 -	un tipo errato		| 0 - OK														//
//--------------------------------------------------------------------------------------------------------------//
int SetPdfAConformanceLevelSalva(string userType, PDFACompliance::Conformance* pdfaLevel) {						// Dichiarazione di funzione
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	WriteLogMessage(__FUNCTION__, "Il livello di conformita PDF/A deve essere impostato a: ", userType);		// Scrie LOG
	if (userType.length() < 2)																					// Se il tipo di conversione PDF/A e mancante o NULL
		return 1;
	//==========================================================================================================//
	if (userType.find("1a") != string::npos)																	// Se il tipo di conversione PDF/A e '1A'
		*pdfaLevel = PDFACompliance::e_Level1A;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 1A 
	else if (userType.find("1b") != string::npos)																// Se il tipo di conversione PDF/A e '1B' 
		*pdfaLevel = PDFACompliance::e_Level1B;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 1B
	else if (userType.find("2a") != string::npos)																// Se il tipo di conversione PDF/A e '2A' 
		*pdfaLevel = PDFACompliance::e_Level2A;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 2A 
	else if (userType.find("2b") != string::npos)																// Se il tipo di conversione PDF/A e '2B' 
		*pdfaLevel = PDFACompliance::e_Level2B;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 2B 
	else if (userType.find("2u") != string::npos)																// Se il tipo di conversione PDF/A e '2U' 
		*pdfaLevel = PDFACompliance::e_Level2U;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 2U 
	else if (userType.find("3a") != string::npos)																// Se il tipo di conversione PDF/A e '3A' 
		*pdfaLevel = PDFACompliance::e_Level3A;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 3A 
	else if (userType.find("3b") != string::npos)																// Se il tipo di conversione PDF/A e '3B' 
		*pdfaLevel = PDFACompliance::e_Level3B;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 3B 
	else if (userType.find("3u") != string::npos)																// Se il tipo di conversione PDF/A e '3U' 
		*pdfaLevel = PDFACompliance::e_Level3U;																	// Inizializza il tipo di output con il livello di conformita PDF/A: Level 3U 
	else																										// Se il tipo di conversione PDF/A non e uno dei precedenti 
		return 1;																								// Restituisce l'errore: un tipo errato
	WriteLogMessage(__FUNCTION__, "Il livello di conformita PDF/A e stato impostato", userType);				// Scrie LOG
	return 0;																									// Restituisce l'errore: OK
}

//--------------------------------------------------------------------------------------------------------------//
// FUNZIONE ReplaceWithEuroSymbol (non esportata)																//
//--------------------------------------------------------------------------------------------------------------//
// FUNZIONI SVOLTE: Sostituisce i simboli non ASCII con quelli in CP1252										//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   valore  string   (I)  : il valore della stringa che ha il string &#num										//
//--------------------------------------------------------------------------------------------------------------//
void ReplaceNonAsciiSymbol(string& valore) {
#ifndef __linux
	int code = GetConsoleOutputCP();																			// Obtine codificarea curenta si memoriaza
	SetConsoleOutputCP(1252);																					// Seteaza codificarea Windows-1252
#endif // __linux
	for (int index = EURO; index < LeNgTh; index++)																// Parcurge toate entitatile (HTML si CP1252) 
	{
		size_t found = valore.find(HTML_CODE[index]);															// Identifica pozitia entitatii HTML in sirul de baza
		while (found < valore.length())																			// Atat timp cat se identifica pozitia entitatii HTML in sir, modifica
		{
			stringstream ss;
			string str;
			ss << (char)(CP1252_CODE[index]);																	// Inscrie in STREAM codul simbolului din CP1252 pentru transformare
			ss >> str;																							// Obtine din STREAM simbolul transformat
			valore.replace(found, strlen(HTML_CODE[index]), str);												// Inlocuieste in sirul de baza simbolul 
			found = valore.find(HTML_CODE[index]);																// Identifica pozitia entitatii HTML in sirul de baza
		}
	}
#ifndef __linux
	SetConsoleOutputCP(code);																					// Intoarce codificarea precedenta
#endif // __linux
}

//--------------------------------------------------------------------------------------------------------------//
// FUNZIONE AddCodeLineNum (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------//
// FUNZIONI SVOLTE: Aggiungere il numero di riga quando si converte il codice da TXT a PDF						//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   value  fin		(I)  : il percorso del file TXT																//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO		string 1 -	un tipo errato		| 0 - OK														//
//--------------------------------------------------------------------------------------------------------------//
string AddCodeLineNum(char* fin) {
	/*----- Dichiarazione e inizializzazione di variabili ------------------------------------------------------*/
	string line;																								//
	long lineCount = 0;																							//
	string tmpPath(fin); tmpPath.append("out");																	//
	ifstream fileIn(fin);																						//
	ofstream fileOut(tmpPath.c_str());																			//
	//==========================================================================================================//
	if (fileIn.is_open()) {																						//
		while (getline(fileIn, line)) {																			//
			if (lineCount < 9) {																				//
				fileOut << "   " << ++lineCount << ": " << line << '\n';										//
				continue;																						//
			}																									//
			if (lineCount < 99) {																				//
				fileOut << "  " << ++lineCount << ": " << line << '\n';											//
				continue;																						//
			}																									//
			if (lineCount < 999) {																				//
				fileOut << " " << ++lineCount << ": " << line << '\n';											//
				continue;																						//
			}																									//
			fileOut << ++lineCount << ": " << line << '\n';														//
		}																										//
		fileOut.close();																						//
		fileIn.close();																							//
	}																											//
	return tmpPath;																								//
}


#ifndef __GNUC__
#pragma endregion
#endif 

#ifndef __GNUC__
#pragma region FUNZIONI DI ORGANIZZAZIONE
#endif 

//--------------------------------------------------------------------------------------------------------------//
// FUNZIONE DecodeInterval																						//
//--------------------------------------------------------------------------------------------------------------//
// FUNZIONI SVOLTE: Decodifica la stringa contenente intervalli e set di pagine									//
//--------------------------------------------------------------------------------------------------------------//
// REVISIONI:																									//
//    - Ticau V. 07/10/20																						//
//--------------------------------------------------------------------------------------------------------------//
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   strInter        string                      (I)  : La stringa da decodificare								//
//    srcNrTotPag    int                         (I)  : Il numero totale di pagine del documento sorgente		//
//    decInter       vector<int>*                (O)  : Il vettore che contiene l'intervallo di pagine da elaborare
//    pageSet        vector<PAGE_INTERVALS>*     (O)  : Il vettore che contiene gruppi di pagine da elaborare	//
//    ordina         int                         (I)  : Ordina il vettore che contiene l'intervallo di pagine	//
//                                                    - 0 : Non ordinare										//
//                                                    - 1 : Ordine crescente (default)							//
//                                                    - 2 : Ordine decrescente									//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO        Esito:																						//
//                            0 : OK																			//
//                            46 : La stringa trasmessa per la decodifica non contiene elementi					//
//                            47 : La stringa trasmessa per la decodifica non inizia con una cifra				//
//                            48 : La stringa trasmessa per la decodifica contiene simboli non ammessi			//
//                            49 : La stringa trasmessa per la decodifica contiene una sequenza di , e -		//
//                            50 : La stringa trasmessa per la decodifica supera la dimensione del file,		//
//                                 e piu piccola o piu grande del numero totale di pagine						//
//--------------------------------------------------------------------------------------------------------------//
int DecodeInterval(string strInter, int srcNrTotPag, vector<int>* decInter, vector<PAGE_SETS>* pageSet, int ordina) {// Dichiarazione di funzione 
	int ret = 0;                                                                                     // Variabile di ritorno: inizializzazione con value 0 (value OK)
	vector<string> combinatii;                                                                       // Seturile de pagini definite de utilizator
	size_t posFound = 0;                                                                             // Pozitia gasita in string a simbolului cautat
	bool haveSet = false;                                                                            // Flag ce indica daca exista seturi specificate sau nu in diapazonul secificat
	int buffInt = 0;                                                                                 // Variabila buffer de tip intreg
	string subInter;                                                                                 // Variabila buffer ce pastreaza diapazonul ramas la parsare
	int elIni, elFin;                                                                                // Elementele de inceput si sfarsit a intervalului
	bool pageSetIsNULL = true;                                                                       // Flag ce specifica daca setul de pagni este NULL

	strInter.erase(remove_if(strInter.begin(), strInter.end(), ::isspace), strInter.end());     // Remove blank spaces 

	/* Verifica daca lungimea sirului este mai mare sau egala cu 1 */
	if (strInter.size() >= 1) {                                                                      // Daca lungimea sirului este mai mare sau egala cu 1
		/* Verifica daca primul caracter este cifra */
		if (!isdigit(strInter.at(0)))                                                                // Daca primul caracter nu este cifra
			return PDF_INTER_WRONG_BEGIN;                                                            // Returneaza eroare: Sirul trebuie sa inceapa cu o cifra
		/* Verifica daca lungimea sirului este egala cu 1 */
		if (strInter.size() == 1) {                                                                  // Daca lungimea sirului este egala cu 1 
			/* Verifica daca primul caracter este 0 */
			if (ConvStrToInt(strInter.c_str()) == 0) {                                               // Daca primul caracter din diapazon este 0
				decInter->push_back(0);                                                              // Inscrie valoarea in vector
				return ret;                                                                          // Dupa inscrierea lui 0, se praseste functia
			}
		}
		/* Verifica daca ultimul caracter este cifra */
		if (!isdigit(strInter.at(strInter.size() - 1))) {                                            // Daca ultimul caracter nu este cifra, 
			strInter.erase(strInter.end() - 1);                                                      // elimina ultimul caracter
		}                                                                                            //
		/* Verifica daca sirul contine alte simboluri decat virgula si cratima */
		if (strInter.find_first_not_of(",-0123456789") != string::npos) {                       // Daca sirul contine alte simboluri decat virgula si cratima
			return PDF_INTER_BAD_SYMBOL;                                                             // Returneaza eroare: Sirul contine simboluri nepermise
		}
		/* Verifica daca sunt intalnite combinatiile ,- sau -, (virgula si cratima alaturi) */
		size_t found = strInter.find(",-");                                                          // Cauta pozitia unuia din caracterele , sau - in diapazon
		if (found == string::npos)                                                              // Daca a fost identificat unul din caractere in sir
			found = strInter.find("-,");                                                             // Cauta pozitia urmatorului astfel de caracter
		if (found != string::npos)                                                              // Daca nu mai sunt intalnite astfel de caractere
			return PDF_INTER_WRONG_SEQ;                                                              // Returneaza eroare: Sunt intalnite combinatii ,- sau -,

		/* Eliminarea dublarilor de virgula ,, */
		posFound = strInter.find(",,");                                                              // Cauta pozitia virgulei duble
		while (posFound != string::npos) {                                                           // Atat timp cat nu este gasita dublarea virgulei
			strInter.erase(posFound, 1);                                                             // Elimina caracter cu caracter din sirul cautat
			posFound = strInter.find(",,");                                                          // Cauta pozitia virgulei duble
		}

		/* Eliminarea dublarilor de cratima -- */
		posFound = strInter.find("--");                                                              // Cauta pozitia cratimei duble
		while (posFound != string::npos) {                                                           // Atat timp cat nu este gasita dublarea cratimei
			strInter.erase(posFound, 1);                                                             // Elimina caracter cu caracter din sirul cautat
			posFound = strInter.find("--");                                                          // Cauta pozitia cratimei duble
		}

		/* Extrage toate numerele din seturi separat pentru verificare
		- Daca unul din numere este mai mic ca 1, se va returna eroare
		- Daca unul din numere este mai mare ca NrTP, va returna eroare */
		subInter = strInter;                                                                         // Stocheaza intr-o alta variabila valoarea intervalului de baza
		haveSet = false;                                                                             // Reseteaza flagul
		do {
			posFound = subInter.find_first_of(",-");                                                 // Cauta pozitia separatorului , sau -
			if (posFound)                                                                            // Daca este gasita cel putin o virgula, exista set de pagini
				haveSet = true;                                                                      // Sirul contine mai mult de un set
			buffInt = ConvStrToInt(subInter.substr(0, posFound));                                    // Converteste din string in int si stocheaza valoarea
			if (buffInt < 1 || buffInt > srcNrTotPag)                                                // Verifica daca elementul este mai mic / mai mare ca dimensiunea documentului
				return PDF_INTER_OUT_OF_DOC;                                                         // Unul din seturi depaseste dimensiunile documentului
			if (haveSet)                                                                             // Daca exista set, se trunchiaza sirul pt a extrage celalte seturi
				subInter = subInter.substr(posFound + 1, subInter.length());                         // Se salveaza ultima sectiune a sirului ramasa
		} while (posFound != string::npos);                                                          // Cat timp nu este final de sir, cauta combinatii

		/* Extrage combinatiile din sir dupa separatorul , */
		haveSet = false;                                                                             // Reseteaza flagul
		do {
			posFound = strInter.find(',');                                                           // Cauta pozitia separatorului ,
			if (posFound)                                                                            // Daca este gasita cel putin o virgula, exista set de pagini
				haveSet = true;                                                                      // Sirul contine mai mult de un set
			combinatii.push_back(strInter.substr(0, posFound));                                      // Stocheaza combinatia in vector
			if (haveSet)                                                                             // Daca exista set, se trunchiaza sirul pt a extrage celalte seturi
				strInter = strInter.substr(posFound + 1, strInter.length());                         // Se salveaza ultima sectiune a sirului ramasa
		} while (posFound != string::npos);                                                          // Cat timp nu este final de sir, cauta combinatii

		if (!pageSet)                                                                                // Daca nu exista elemente in vector
			pageSetIsNULL = false;                                                                   // Dezactiveaza flagul referitor la pagini

		/* Converteste intervalele in siruri de numere */
		for (int i = 0; i < static_cast<int>(combinatii.size()); i++) {                              // Parcurge toate combinatiile pentru a identifica intervale
			if (pageSetIsNULL)                                                                       // Daca flagul referitor la pagini este ACTIV
				pageSet->push_back(PAGE_SETS());                                                     // Adauga la sfarsit obiect nou creat cu constructorul implicit.
			posFound = combinatii.at(i).find('-');                                                   // Cauta daca exista cratimei si extrage pozitia acesteia
			if (posFound == string::npos) {                                                          // Daca nu exista cratima
				buffInt = ConvStrToInt(combinatii.at(i));                                            // Incarca in buffer caloarea convertita in INT
				decInter->push_back(buffInt);                                                        // Se converteste direct elementul in int si se plaseaza in vectorul de pagini
				if (pageSetIsNULL) {                                                                 // Daca flagul referitor la pagini este ACTIV
					pageSet->at(i).start = buffInt;                                                  // Se atribuie obiectului de pe pozitia i de start valoarea buferului
					pageSet->at(i).end = buffInt;                                                    // Se atribuie obiectului de pe pozitia i de finis valoarea buferului
				}
			}
			else {                                                                                   // Daca exista cratima
				elIni = ConvStrToInt(combinatii.at(i).substr(0, posFound));                          // Se stocheaza elementul de start al intervalului
				elFin = ConvStrToInt(combinatii.at(i).substr(posFound + 1, string::npos));           // Se stocheaza elementul de final al intervalului
				if (pageSetIsNULL) {                                                                 // Daca flagul referitor la pagini este ACTIV
					pageSet->at(i).start = elIni;                                                    // Se atribuie obiectului de pe pozitia i de start valoarea primului element
					pageSet->at(i).end = elFin;                                                      // Se atribuie obiectului de pe pozitia i de start valoarea ultimului element
				}                                                                                    //

				/* Determina ordinea setului (Ascendent, Descendent)*/
				if (elIni < elFin) {                                                                 // Daca intervalul este ordonat in mod Ascendent
					/* Interval ordonat Ascendent */
					for (int j = elIni; j <= elFin; j++)                                             // Parcurge toate elementele de la Start - Finis
						decInter->push_back(j);                                                      // Inscrie valorile obtinute in vectorul de pagini
				}
				else {                                                                               // Daca intervalul este ordonat in mod Descendent
					/* Interval ordonat Descendent */
					for (int j = elIni; j >= elFin; j--)                                             // Parcurge toate elementele de la Finis - Start
						decInter->push_back(j);                                                      // Inscrie valorile obtinute in vectorul de pagini
				}
			}
		}

		/* Ordoneaza vectorul */
		switch (ordina) {                                                                            // 
		case 1:                                                                                      // Daca ordina este 1
			sort(decInter->begin(), decInter->end());                                                // Ordoneaza ascendent
			break;
		case 2:                                                                                      // Daca ordina este 2
			sort(decInter->end(), decInter->begin());                                                // Ordoneaza descendent
			break;
		default:                                                                                     // Daca ordina este al numar
			break;
		}

		/* Eliminarile dublarile de numere */                                                        //
		decInter->erase(unique(decInter->begin(), decInter->end()), decInter->end());                // Eliminarile dublarile de numere din interval
	}
	else                                                                                             // Daca lungimea sirului este mai mica ca 1
		return PDF_INTER_MISS;                                                                       // Returneaza eroare: Sirul nu contine elemente
	return ret;                                                                                      // Returneaza valoarea lui RET
}

//--------------------------------------------------------------------------------------------------------------//
// FUNZIONE GetDegreesFromStr																					//
//--------------------------------------------------------------------------------------------------------------//
// FUNZIONI SVOLTE: Decodifica la stringa che contiene i gradi di rotazione della pagina						//
//--------------------------------------------------------------------------------------------------------------//
// REVISIONI:																									//
//    - Ticau V. 14/10/20																						//
//--------------------------------------------------------------------------------------------------------------//
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   strDegrees    string            (I)  : La stringa da decodificare											//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO        Esito:																						//
//                            0 : La stringa non contiene un valore di rotazione consentito (default)			//
//                           -90 : La rotazione deve essere eseguita a -90 gradi (antiorario)					//
//                            90 : La rotazione deve essere eseguita a 90 gradi (senso orario)					//
//                           180 : La rotazione deve essere eseguita a 180 gradi								//
//--------------------------------------------------------------------------------------------------------------//
int GetDegreesFromStr(string strDegrees) {																		// Dichiarazione di funzione 
	int ret = 0;																								// Variabile di ritorno: inizializzazione con value 0 (value OK)
	size_t found = 0;																							// Pozitie de identificare

	/* Remove blank spaces*/																					//
	strDegrees.erase(remove_if(strDegrees.begin(), strDegrees.end(), ::isspace), strDegrees.end());				// Remove blank spaces

	/* In urma eliminarii spatiilor, sirul trebuie sa contina 3 caractere										//
	in caz contrar, se va returna 0 */																			//
	//if (strDegrees.size() != 3)
	//    return 0;

	/* Verifica daca sirul contine alte simboluri decat cele permise */
	if (strDegrees.find_first_not_of("-+0189") != string::npos)													// Daca sirul contine alte simboluri decat cele permise
		return 0;																								// Sirul contine simboluri nepermise, rotatia se va efectua la 0 grade

	/* Cauta in sir numarul de grade */																			//
	found = strDegrees.find("-90");																				// Identifica pozitia in string a urmatorului substring: "-90"
	if (found != string::npos)																					// Daca substringul a fost gasit
		return -90;																								// Sirul contine -90, rotatia se va efectua la 270 grade
	else {																										// Daca nu a fost gasit
		found = strDegrees.find("+90");																			// Identifica pozitia in string a urmatorului substring: "+90"
		if (found != string::npos)																				// Daca substringul a fost gasit
			return 90;																							// Sirul contine +90, rotatia se va efectua la 90 grade
		else {																									// Daca nu a fost gasit
			found = strDegrees.find("90");																		// Identifica pozitia in string a urmatorului substring: "90"
			if (found != string::npos)																			// Daca substringul a fost gasit
				return 90;																						// Sirul contine 90, rotatia se va efectua la 90 grade
			else {																								// Daca nu a fost gasit
				found = strDegrees.find("180");																	// Identifica pozitia in string a urmatorului substring: "180"
				if (found != string::npos)																		// Daca substringul a fost gasit
					return 180;																					// Sirul contine 180, rotatia se va efectua la 180 grade
				else																							// Daca nu a fost gasit
					return 0;																					// Sirul contine alt numar de grade, rotatia se va efectua la 0 grade
			}
		}
	}
	return ret;																									// Sirul nu contine numar permis de grade, rotatia se va efectua la 0 grade
}

//--------------------------------------------------------------------------------------------------------------//
// FUNZIONE GetPageRotation																						//
//--------------------------------------------------------------------------------------------------------------//
// FUNZIONI SVOLTE: Identifica la posizione di rotazione della pagina in base ai gradi indicati dall'utente		//
//--------------------------------------------------------------------------------------------------------------//
// REVISIONI:																									//
//    - Ticau V. 14/10/20																						//
//--------------------------------------------------------------------------------------------------------------//
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//   page        Page            (I)  : Pagina da ruotare														//
//   degrees     int             (I)  : Gradi indicati dall'utente												//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO        Di quanti gradi deve ruotare la pagina														//
//--------------------------------------------------------------------------------------------------------------//
Page::Rotate GetPageRotation(Page page, int degrees) {															// Dichiarazione di funzione 
	Page::Rotate originalRotation = page.GetRotation();															// Extrage rotirea initiala
	Page::Rotate rotation = Page::e_0;																			// Seteaza rotirea cu 0 grade

	/* Identifica rotirea dupa modul indicat de user */
	switch (degrees) {																							//
	case -90:																									// Roteste la -90 grade, fata de pozitia initiala
		switch (originalRotation) {																				//
		case Page::e_0:   rotation = Page::e_270;    break;														//
		case Page::e_90:  rotation = Page::e_0;      break;														//
		case Page::e_180: rotation = Page::e_90;     break;														//
		case Page::e_270: rotation = Page::e_180;    break;														//
		default:          rotation = Page::e_0;      break;														//
		}																										//
		break;																									//
	case 90:																									// Roteste la 90 grade, fata de pozitia initiala
		switch (originalRotation) {																				//
		case Page::e_0:   rotation = Page::e_90;     break;														//
		case Page::e_90:  rotation = Page::e_180;    break;														//
		case Page::e_180: rotation = Page::e_270;    break;														//
		case Page::e_270: rotation = Page::e_0;      break;														//
		default:          rotation = Page::e_0;      break;														//
		}																										//
		break;																									//
	case 180:																									// Roteste la 180 grade, fata de pozitia initiala
		switch (originalRotation) {																				//
		case Page::e_0:   rotation = Page::e_180;    break;														//
		case Page::e_90:  rotation = Page::e_270;    break;														//
		case Page::e_180: rotation = Page::e_0;      break;														//
		case Page::e_270: rotation = Page::e_90;     break;														//
		default:          rotation = Page::e_0;      break;														//
		}																										//
		break;																									//
	default:																									// Roteste la 0 grade, fata de pozitia initiala
		rotation = Page::e_0;																					//
		break;																									//
	}																											//
	return rotation;																							// Returneaza rotirea paginii
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE GetPathPart																							//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Estrai parti del percorso																	//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 12-12-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	filePath    char*	(I) : Il percorso del file																//
//	parte       int		(I) : Indica la parte da estrarre														//
//							1 - Percorso della directory														//
//							2 - Nome file senza estensione														//
//							3 - Nome file con estensione														//
//							4 - Estensione																		//
//							5 - VUOTO se manca l'estensione														//
//--------------------------------------------------------------------------------------------------------------//
// RITORNO:																										//
//					string	- La parte indicata del percorso													//
//--------------------------------------------------------------------------------------------------------------// 
string GetPathPart(char* filePath, int parte) {																	// Dichiarazione di funzione 
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	string str(filePath);																						//
	size_t found = 0;																							//
	char part[256] = "";																						//
	//==========================================================================================================//
	switch (parte)																								//
	{																											//
	case 1: {																									// return File Dir                        // Result: Path
#ifdef __linux
		found = str.find_last_of("//");
#else    
		found = str.find_last_of("/\\");																		//
#endif    
		strcpy(part, str.substr(0, found).c_str());																//
		return part;																							//
	}																											//
	case 2: {																									// return File Name without extension        // Result: Filename
#ifdef __linux
		found = str.find_last_of("//");
#else    
		found = str.find_last_of("/\\");																		//
#endif    
		str = str.substr(found + 1);																			//
		found = str.find_last_of("/.");																			//
		strcpy(part, str.substr(0, found).c_str());																//
		return part;																							//
	}																											//
	case 3: {																									// return File Name wit extension            // Result: Filename + Extension    
#ifdef __linux
		found = str.find_last_of("//");
#else    
		found = str.find_last_of("/\\");																		//
#endif    
		strcpy(part, str.substr(found + 1).c_str());															//
		return part;																							//
	}																											//
	case 4: {																									// return Extension                        // Result: "." + Extension 
#ifdef __linux
		found = str.find_last_of(".");																			//
#else    
		found = str.find_last_of("/.");																			//
#endif    
		if (found == string::npos)																				//
			break;																								//
		strcpy(part, str.substr(found + 1).c_str());															//
		return part;																							//
	}																											//
	case 5: {																									// return Extension if not missing        // Result: "." + Extension or VUOTO
#ifdef __linux
		found = str.find_last_of(".");																			//
#else    
		found = str.find_last_of("/.");																			//
#endif    
		if (found == string::npos)																				//
			strcpy(part, "");																					//
		else																									//
		{																										//
			strcpy(part, str.substr(found + 1).c_str());														//
		}																										//
		return part;																							//
	}																											//
	default:																									//
		break;																									//
	}																											//
	return filePath;																							//
}

//--------------------------------------------------------------------------------------------------------------//
//FUNZIONE CheckDirectoryExists (non esportata)																	//
//--------------------------------------------------------------------------------------------------------------//
//FUNZIONI SVOLTE: Controlla che la directory esista															//
//--------------------------------------------------------------------------------------------------------------//
//ARGOMENTI:																									//
//  dirPath        char*    (I)  : percorso della directory														//
//--------------------------------------------------------------------------------------------------------------//
//RITORNO																										//
//           true : esista																						//
//           false: non esista																					//
//--------------------------------------------------------------------------------------------------------------//
bool CheckDirectoryExists(char* dirPath) {																		// Dichiarazione di funzione 
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	if (dirPath == NULL) {																						// Daca pointerul nu contine valoare
		return false;																							// Returneaza: Folderul nu exista
	}																											//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char* pDirPath = (char*)malloc((strlen(dirPath) + 1) * sizeof(char));											// Declara buffer si aloca memorie pentru acesta 
	//==========================================================================================================//
	strcpy(pDirPath, dirPath);																					// Preia valoarea pointerului in variabila 
	size_t i = strlen(pDirPath) - 1;																			// Extrage lungimea valorii
	if (pDirPath[i] == H_TREE)																					// Daca ultimul caracter este H_TREE
		pDirPath[i] = '\0';																						// Specifica utlimul caracter ca terminator
	struct STAT buffer;																							// Structura STAT ce indica statutul elementului
	if (STAT(pDirPath, &buffer) == 0) {																			// Daca statutul elementului este identificat
		free(pDirPath);																							// Libera la memoria del puntatore
		if (buffer.st_mode & S_IFDIR)																			// Daca statutul elementului indica ca este folder
			return true;																						// Returneaza: Folderul exista
		else																									// Daca statutul elementului indica ca nu este folder
			return false;																						// Returneaza: Folderul nu exista
	}
	free(pDirPath);																								// Libera la memoria del puntatore
	return false;																								// Returneaza: Folderul nu exista
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE CheckFileExists																						//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Controlla che il file esista																//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   filePath    char*    (I)  : Percorso dell file																//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO																										//
//            true : esista																						//
//            false: non esista																					//
//--------------------------------------------------------------------------------------------------------------// 
bool CheckFileExists(char* filePath) {																			// Dichiarazione di funzione 
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	bool exist = false;																							// Falg ce indica daca fisierul exista sau nu, DEZACTIVAT initial
	struct STAT buffer;																							// Structura STAT ce indica statutul elementului
	//==========================================================================================================//
	if (STAT(filePath, &buffer) == 0) {																			// Daca statutul elementului este identificat
		if (buffer.st_size)																						// Daca in statutul elementului este identificata marimea acestuia fiind pozitiva
			exist = true;																						// Activeaza flagul: Fisierul exista
	}
	return exist;																								// Returneaza flagul ce indica daca fisierul exista sau nu
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE ConvStrToInt (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Converte una stringa di cifre in tipo INT													//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//  str        string        (I)  : La stringa di cifre															//
//		(O) string - result of conversion in char* format														//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO    Il numero nella stringa																			//
//--------------------------------------------------------------------------------------------------------------// 
int ConvStrToInt(string str) {																					// Dichiarazione di funzione 
	stringstream sstr(str);																						// object from the class stringstream 
	int x = 0;																									//
	sstr >> x;																									// The object has the value STR and stream it to the integer x 
	return x;																									// Now the variable x holds the value STR
}

#ifndef __GNUC__
#pragma endregion 
#endif 

#ifndef __GNUC__
#pragma region FUNZIONI DI LOG
#endif 

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE setLevelLog (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Seteaza nivelul de LOG pentru scriere														//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   logLevel		int   (I)  : nivelul de LOG	[pana la 9]														//
//--------------------------------------------------------------------------------------------------------------// 
void setLevelLog(int logLevel) {
	_logLevel = logLevel;
}
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE getLevelLog (non esportata)																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Obtine nivelul de LOG pentru scriere														//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO       short - nivelul de LOG																			//
//--------------------------------------------------------------------------------------------------------------// 
short getLevelLog() {
	return _logLevel;
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE WriteLogExceptionPDF (non esportata)																//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Scrivi nel file LOG il nome della funzione che ha generato l'eccezione e il messaggio		//
// dell'eccezione PDFNet																						//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   nomFunz      const char*   (I)  : Il nome di funzione														//
//   eccezione    Exception     (I)  : Il messaggio di eccezione												//
//--------------------------------------------------------------------------------------------------------------// 
void WriteLogExceptionPDF(const char* nomFunz, Common::Exception eccezione) {									// Dichiarazione di funzione 
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	ofstream wpriLogOutStream;																					// Stream-ul de OUPTUT pentru WPRI
	char hstPathLog[50];																						// Calea catre fisierul de LOG
	unsigned long pid = 0;																						// Process ID
	//==========================================================================================================//
#ifdef WIN32
	pid = GetCurrentProcessId();																				// Prendo il PID
#else
	pid = getpid();																								// Prendo il PID
#endif                
	sprintf(hstPathLog, "%swpri-exception.log", DIR_HTMP);														// Formeaza calea cate fisierul 'wpri-exception.log'

	char LocalDateTimeNow[DATE_TIME];
	GetLocalDateTimeNow(LocalDateTimeNow, sizeof(LocalDateTimeNow));											// Obtine timpul curent

	wpriLogOutStream.open(hstPathLog, ios::app);																// Incarca/Creaza fisierul de LOG
	if (wpriLogOutStream.is_open()) {																			// Daca fisierul a fost accesat
		wpriLogOutStream << "---------------------------------------------------------------------------------------------------" << endl;// Adauga separator
		wpriLogOutStream << LocalDateTimeNow << " | " << pid << " | " << nomFunz << " ---> --> ->" << endl;		// Inscrie in fisier: DateTime | PID | __FUNCTION__
		wpriLogOutStream << "---------------------------------------------------------------------------------------------------" << endl;// Adauga separator
		wpriLogOutStream << eccezione;																			// Inscrie in fisier : PDF EXCEPTION
		wpriLogOutStream << "===================================================================================================\n" << endl;// Adauga separator
		wpriLogOutStream.close();																				// Inchide stream
	}																											//
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE WriteLogMessage (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Scrivi un messaggio indicato dal programmatore nel file LOG (Usato per DEBUG)				//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   message			const char*		(I)  : Il messagio														//
//--------------------------------------------------------------------------------------------------------------// 
void WriteLogMessage(const char* message) {																		// Dichiarazione di funzione 
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	if (getLevelLog() <= 0) return;																				// Daca nivelul de LOG este mai mic sau egal cu 0, paraseste executia
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	FILE* fpLog = NULL;																							// Pointerul carte fisierul 'wpri-zz-mm-yy.log'
	char hstPathLog[50];																						// Calea catre fisierul de LOG
	unsigned long pid = 0;																						// Process ID
	//==========================================================================================================//
#ifdef WIN32
	pid = GetCurrentProcessId();																				// Prendo il PID
#else
	pid = getpid();																								// Prendo il PID
#endif                
	char LocalDateNow[DATE_SIZE];
	GetLocalDataNow(LocalDateNow, sizeof(LocalDateNow));														// Obtine timpul curent
	sprintf(hstPathLog, "%swpri-%s.log", DIR_HTMP, LocalDateNow);												// Formeaza calea cate fisierul 'wpri-zz-mm-yy.log'
	/*----- Scrie in fisierul LOG ------------------------------------------------------------------------------*/
	fpLog = fopen(hstPathLog, "a+");																			// Deschide fisierul in mod adaugare
	if (!fpLog) return;																							// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
	char LocalTimeNow[TIME_SIZE];
	GetLocalTimeNow(LocalTimeNow, sizeof(LocalTimeNow));														// Obtine timpul curent
	fprintf(fpLog, "%s | %ld | %s\n", LocalTimeNow, pid, message);												// Inscrie in fisier: DateTime | PID | MESSAGE
	fprintf(fpLog, "---------------------------------------------------------------------------------------------------\n");// Inscrie in fisier: SEPARATOR
	fclose(fpLog);																								// Daca fisierul este deschis, inchide-l
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE WriteLogMessage (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Scrivi un messaggio indicato dal programmatore nel file LOG (Usato per DEBUG)				//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   nomFunz			const char*   (I)  : Il nome di funzione												//
//   message			const char*   (I)  : Il messagio														//
//--------------------------------------------------------------------------------------------------------------// 
void WriteLogMessage(const char* nomFunz, const char* message) {												// Dichiarazione di funzione 
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	if (getLevelLog() <= 0) return;																				// Daca nivelul de LOG este mai mic sau egal cu 0, paraseste executia
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	FILE* fpLog = NULL;																							// Pointerul carte fisierul 'wpri-zz-mm-yy.log'
	char hstPathLog[50];																						// Calea catre fisierul de LOG
	unsigned long pid = 0;																						// Process ID
	//==========================================================================================================//
#ifdef WIN32
	pid = GetCurrentProcessId();																				// Prendo il PID
#else
	pid = getpid();																								// Prendo il PID
#endif                
	char LocalDateNow[DATE_SIZE];
	GetLocalDataNow(LocalDateNow, sizeof(LocalDateNow));														// Obtine timpul curent
	sprintf(hstPathLog, "%swpri-%s.log", DIR_HTMP, LocalDateNow);												// Formeaza calea cate fisierul 'wpri-zz-mm-yy.log'
	/*----- Scrie in fisierul LOG ------------------------------------------------------------------------------*/
	fpLog = fopen(hstPathLog, "a+");																			// Deschide fisierul in mod adaugare
	if (!fpLog) return;																							// Daca nu s-a putut deschide fisierul  atunci paraseste functia 
	char LocalTimeNow[TIME_SIZE];
	GetLocalTimeNow(LocalTimeNow, sizeof(LocalTimeNow));														// Obtine timpul curent
	fprintf(fpLog, "%s | %ld | %s | %s", LocalTimeNow, pid, nomFunz, message);									// Inscrie in fisier: DateTime | PID | __FUNCTION__ | MESSAGE 
	if (getLevelLog() >= 8) {																					// Daca nivelul este >=8 [Trace Memory]
		long long memTotal = 0, memFree = 0, memUsage = 0;														// Declara variabile pentru valorile de memorie
#ifdef WIN32
		// Alocare de memorie pentru un proces
		HANDLE hProcess = GetCurrentProcess();
		PROCESS_MEMORY_COUNTERS pmc;

		if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
			memUsage = pmc.WorkingSetSize / 1024;																// Convertire in KB

		// Info despre memoria disponibila in sistem
		MEMORYSTATUSEX memoryStatus;
		memoryStatus.dwLength = sizeof(memoryStatus);

		if (GlobalMemoryStatusEx(&memoryStatus)) {
			memTotal = memoryStatus.ullTotalPhys / 1024;														// Convertire in KB
			memFree = memoryStatus.ullAvailPhys / 1024;															// Convertire in KB
		}
#else
		FILE* file = fopen("/proc/meminfo", "r");
		if (fscanf(file, "MemTotal: %lld kB\nMemFree: %lld kB", &memTotal, &memFree) != 2) {
			fclose(file);
		}
		fclose(file);

		struct rusage r_usage;
		getrusage(RUSAGE_SELF, &r_usage);
		memUsage = r_usage.ru_maxrss;
#endif                
		fprintf(fpLog, " | Mem. usage: [%lld] Kb | Mem. free: [%lld] Kb", memUsage, memFree);					// Inscrie in fisier: | MEM USAGE | MEM FREE
	}
	fprintf(fpLog, "\n");																						// Inscrie in fisier: NewLine
	fprintf(fpLog, "---------------------------------------------------------------------------------------------------\n");// Inscrie in fisier: SEPARATOR
	fclose(fpLog);																								// Daca fisierul este deschis, inchide-l
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE WriteLogMessage (non esportata)																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONI SVOLTE: Scrivi un messaggio indicato dal programmatore nel file LOG (Usato per DEBUG)				//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   nomFunz			const char*   (I)  : Il nome di funzione												//
//   message			const char*   (I)  : Il messagio														//
//   param				string        (I)  : Il parametro														//
//--------------------------------------------------------------------------------------------------------------// 
void WriteLogMessage(const char* nomFunz, const char* message, string param) {						// Dichiarazione di funzione 
	//----- Controlli preliminari ------------------------------------------------------------------------------//
	if (getLevelLog() <= 0) return;																				// Daca nivelul de LOG este mai mic sau egal cu 0, paraseste executia
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	FILE* fpLog = NULL;																							// Pointerul carte fisierul 'wpri-zz-mm-yy.log'
	char hstPathLog[50];																						// Calea catre fisierul de LOG
	unsigned long pid = 0;																						// Process ID
	long long memTotal = 0, memFree = 0, memUsage = 0;															// Declara variabile pentru valorile de memorie
	char tipoSO[9] = "";																							// Tipul SO
	//==========================================================================================================//
#ifdef WIN32
	strcpy(tipoSO, "Windows");																					// Indica ca este Windows
	pid = GetCurrentProcessId();																				// Prendo il PID

	// Alocare de memorie pentru un proces
	HANDLE hProcess = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;

	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
		memUsage = pmc.WorkingSetSize / 1024;																	// Convertire in KB

	// Info despre memoria disponibila in sistem
	MEMORYSTATUSEX memoryStatus;
	memoryStatus.dwLength = sizeof(memoryStatus);

	if (GlobalMemoryStatusEx(&memoryStatus)) {
		memTotal = memoryStatus.ullTotalPhys / 1024;															// Convertire in KB
		memFree = memoryStatus.ullAvailPhys / 1024;																// Convertire in KB
	}
#else
	strcpy(tipoSO, "Linux");																					// Indica ca este Linux
	pid = getpid();																								// Prendo il PID

	FILE* file = fopen("/proc/meminfo", "r");
	if (fscanf(file, "MemTotal: %lld kB\nMemFree: %lld kB", &memTotal, &memFree) != 2) {
		fclose(file);
	}
	fclose(file);

	struct rusage r_usage;
	getrusage(RUSAGE_SELF, &r_usage);
	memUsage = r_usage.ru_maxrss;
#endif                
	char LocalDateNow[DATE_SIZE];
	GetLocalDataNow(LocalDateNow, sizeof(LocalDateNow));														// Obtine timpul curent
	sprintf(hstPathLog, "%swpri-%s.log", DIR_HTMP, LocalDateNow);												// Formeaza calea cate fisierul 'wpri-zz-mm-yy.log'
	/*----- Scrie in fisierul LOG ------------------------------------------------------------------------------*/
	fpLog = fopen(hstPathLog, "a+");																			// Deschide fisierul in mod adaugare
	if (!fpLog) return;																							// Daca nu s-a putut deschide fisierul  atunci paraseste functia 

	if (strstr(nomFunz, "InitializaWriteLog") != NULL) {														// Daca este functia "InitializaWriteLog"
		char LocalTimeNow[TIME_SIZE];
		GetLocalTimeNow(LocalTimeNow, sizeof(LocalTimeNow));													// Obtine timpul curent
		fprintf(fpLog, "%s | %ld |>>>>> La libreria [%s] e allegata al processo HSR | Mem. totale: [%lld] Kb >>>>>| SO: [%s]", LocalTimeNow, pid, param.c_str(), memTotal, tipoSO);	// Inscrie in fisier:  DateTime | PID | __FUNCTION__ | LIB VER | MEM TOTALE
	}
	else if (strstr(nomFunz, "TerminatePDFNetC") != NULL) {														// Daca este functia "TerminaPDFNetC"
		char LocalTimeNow[TIME_SIZE];
		GetLocalTimeNow(LocalTimeNow, sizeof(LocalTimeNow));													// Obtine timpul curent
		fprintf(fpLog, "%s | %ld |<<<<< La libreria WPRI e staccata dal processo HSR | Memoria usata: [%lld] Kb <<<<<|", LocalTimeNow, pid, memUsage);	// Inscrie in fisier:  DateTime | PID | __FUNCTION__ | MEM USATA
	}
	else																										// Inalte cazuri
	{
		char LocalTimeNow[TIME_SIZE];
		GetLocalTimeNow(LocalTimeNow, sizeof(LocalTimeNow));													// Obtine timpul curent
		fprintf(fpLog, "%s | %ld | %s | %s", LocalTimeNow, pid, nomFunz, message);								// Inscrie in fisier: DateTime | PID | __FUNCTION__ | MESSAGE 
		fprintf(fpLog, " | %s", param.c_str());																	// Inscrie in fisier:  | PARAM
		if (getLevelLog() >= 8) {																				// Daca nivelul este >=8 [Trace Memory]
			fprintf(fpLog, " | Mem. usage: [%lld] Kb | Mem. free: [%lld] Kb", memUsage, memFree);				// Inscrie in fisier: | MEM USAGE | MEM FREE
		}
	}
	fprintf(fpLog, "\n");																						// Inscrie in fisier: NewLine
	fprintf(fpLog, "---------------------------------------------------------------------------------------------------\n");// Inscrie in fisier: SEPARATOR
	fclose(fpLog);																								// Daca fisierul este deschis, inchide-l
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: GetLocalDataNow																					//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina data curenta din sistem															//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   DateNow			char&   (I)  : Data curenta																//
//   DateNowLen			size_t  (I)  : Lungimea sirului 														//
//--------------------------------------------------------------------------------------------------------------//
void GetLocalDataNow(char* DateNow, size_t DateNowLen) {														//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	time_t t;																									// Variabila de timp
	struct tm* tm;																								// Structura de timp, initializata cu timpul local
	//==========================================================================================================// 
	time(&t);																									// Obtine valoare de timp
	tm = localtime(&t);																							// Initializeaza structura de timp								
	strftime(DateNow, DateNowLen, "%d-%m-%y", tm);            													// Formateaza valoarea de timp dupa formatul specificat
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: GetLocalTimeNow																					//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina timpul curenta din sistem															//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   TimeNow			char&   (I)  : Ora curenta																//
//   TimeNowLen			size_t  (I)  : Lungimea sirului 														//
//--------------------------------------------------------------------------------------------------------------//
void GetLocalTimeNow(char* TimeNow, size_t TimeNowLen) {
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	time_t t;																									// Variabila de timp
	struct tm* tm;																								// Structura de timp, initializata cu timpul local
	//==========================================================================================================// 
	time(&t);																									// Obtine valoare de timp
	tm = localtime(&t);																							// Initializeaza structura de timp								
	strftime(TimeNow, TimeNowLen, "%H:%M:%S", tm);            													// Formateaza valoarea de timp dupa formatul specificat
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: GetLocalDateTimeNow																				//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina data si timpul curent din sistem													//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   DateTimeNow		char&   (I)  : Data si ora curenta														//
//   DateTimeNowLen		size_t  (I)  : Lungimea sirului 														//
//--------------------------------------------------------------------------------------------------------------//
void GetLocalDateTimeNow(char* DateTimeNow, size_t DateTimeNowLen) {
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	time_t t;																									// Variabila de timp
	struct tm* tm;																								// Structura de timp, initializata cu timpul local
	//==========================================================================================================// 
	time(&t);																									// Obtine valoare de timp
	tm = localtime(&t);																							// Initializeaza structura de timp								
	strftime(DateTimeNow, DateTimeNowLen, "%d-%m-%y %H:%M:%S", tm);            									// Formateaza valoarea de timp dupa formatul specificat
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: GetIndexOfAnnotOnPage																				//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina index-ul adnotarii in pagina. Se refera la adnotarea SEMNATURA					//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 24-01-2025 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//   page			Page	(I)  : Obiectul Page in care se cauta adnotarea										//
//   objNum			int		(I)  : Numarul obiectului 															//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO			int - index-ul obiectului cautat															//
//--------------------------------------------------------------------------------------------------------------//
int GetIndexOfAnnotOnPage(Page page, int objNum) {																// Dichiarazione di funzione 
	for (int i = 0; i < page.GetNumAnnots(); ++i) {																// Parseaza toate adnotarile din pagina 
		Annot annot = page.GetAnnot(i);																			// Stocheaza obiectul adnotarii curente
		if (annot.GetSDFObj().GetObjNum() == objNum)															// Daca numarul adnotarii curente coincide cu numarul obiectului cautat
			return i;																							// Returneaza index-ul obiectului
	}
	return -1;																									// Daca nu s-a gasit, returneaza -1
}
#ifndef __GNUC__
#pragma endregion 
#endif 

