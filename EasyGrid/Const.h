//default
extern double PLANET_LAT_DEFAULT = 40035000;
extern double PLANET_LON_DEFAULT = 40075000;
extern char* BOX_SIZE_DEFAULT = "500";
extern char* POINT_TYPE_DEFAULT = "EN";

//errors
extern char* ERROR_LAST_SELECTION = "Возможно проблема в заключается в том,\nчто программа не расположена в директории SAS Planet.\nЕсли так, закройте программу и переместите её в папку с программой SAS Planet.";
extern char* ERROR_LAST_SELECTION_HEADER = "Ошибка копирования из файла LastSelection.hlg";
extern char* ERROR_INPUT_POINT_HEADER = "Ошибка ввода координат";
extern char* ERROR_INPUT_LAT_1 = "В поле <Левый верхний угол/Долгота (Lat)> не число!";
extern char* ERROR_INPUT_LON_1 = "В поле <Левый верхний угол/Широта (Lon)> не число!";
extern char* ERROR_INPUT_LAT_2 = "В поле <Правый нижний угол/Долгота (Lat)> не число!";
extern char* ERROR_INPUT_LON_2 = "В поле <Правый нижний угол/Широта (Lon)> не число!";
extern char* ERROR_INPUT_BOX_HEADER = "Ошибка выбора параметров квадрата сетки";
extern char* ERROR_INPUT_BOX_SIZE = "В поле <Размер квадрата сетки> не число!";
extern char* ERROR_INPUT_BOX = "В поле <Размер квадрата сетки> не число!";
extern char* ERROR_INPUT_POINTS_TYPE = "В поле <Тип обозначения точек> ничего не выбрано!";
extern char* ERROR_LAT_MORE = "У левого верхнего угла не может быть широта больше, чем у нижнего правого угла.\nПроверьте корректность введенных координат.";
extern char* ERROR_LON_MORE = "У левого верхнего угла не может быть долгота меньше, чем у нижнего правого угла.\nПроверьте корректность введенных координат.";

//const
extern char* ALPHABET_RU_DEFAULT = "АБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЭЮЯ";
extern char* ALPHABET_EN_DEFAULT = "ABCDEFGHIJKLMNOPQRSTUWXYZ";

//xml
extern char* XML_HLMNS = "http://www.topografix.com/GPX/1/1";
extern char* XML_VERSION = "1.0";
extern char* XML_ENCODING = "UTF-8";
extern char* XML_STANDALONE = "yes";

//gpx
extern char* GPX = "gpx";
extern char* GPX_XMLNS = "xmlns";
extern char* GPX_CREATOR = "creator";
extern char* GPX_CREATOR_VALUE = "EasyGrid Version 0.1";
extern char* GPX_VERSION = "version";
extern char* GPX_VERSION_VALUE = "1.1";
extern char* GPX_XMLNS_XSI = "xmlns:xsi";
extern char* GPX_XMLNS_XSI_VALUE = "http://www.w3.org/2001/XMLSchema-instance";
extern char* GPX_XSI_SCHEMALOCATION = "xsi:schemaLocation";
extern char* GPX_XSI_SCHEMALOCATION_VALUE = "http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd";
extern char* GPX_METADATA = "metadata";
extern char* GPX_TIME = "time";
extern char* GPX_BOUNDS = "bounds";
extern char* GPX_MINLAT = "minlat";
extern char* GPX_MINLON = "minlon";
extern char* GPX_MAXLAT = "maxlat";
extern char* GPX_MAXLON = "maxlon";
extern char* GPX_TRK = "trk";
extern char* GPX_NAME = "name";
extern char* GPX_GRID = "grid";
extern char* GPX_TRKSEG = "trkseg";
extern char* GPX_WPT = "wpt";
extern char* GPX_LAT = "lat";
extern char* GPX_LON = "lon";
extern char* GPX_TRKPT = "trkpt";
extern char GPX_DATESEPARATOR = '-';
extern char GPX_TIMESEPARATOR = ':';
extern char* GPX_TIMEFORMAT = "yyyy-mm-dd'T'hh:mm:ss'Z'";

//progressbar
extern int PROGRESSBAR_FULL = 100;
extern int PROGRESSBAR_START = 1;
extern int PROGRESSBAR_SECOND = 10;
extern int PROGRESSBAR_THIRD = 20;
extern int PROGRESSBAR_SAVEFILE = 5;

//points
extern char* POINTS_FILE = "LastSelection.hlg";
extern char* POINT_LAT_MIN = "PointLat_1=";
extern char* POINT_LON_MIN = "PointLon_1=";
extern char* POINT_LAT_MAX = "PointLat_3=";
extern char* POINT_LON_MAX = "PointLon_3=";

//ini
extern char* INI_NAME = "EasyGrid.ini";
extern char* INI_EN = "EN";
extern char* INI_RU = "RU";
extern char* INI_NUM = "NUM";
extern char* INI_BOX = "Box";
extern char* INI_SIZE = "Size";
extern char* INI_POINT = "Point";
extern char* INI_TYPE = "Type";
extern char* INI_SETTING = "Setting";
extern char* INI_PLANET_LAT = "Planet_Lat";
extern char* INI_PLANET_LON = "Planet_Lon";
extern char* INI_ALPHABET_EN = "Alphabet_EN";
extern char* INI_ALPHABET_RU = "Alphabet_RU";
extern char* INI_FILE = "File";
extern char* INI_LAST = "Last";

//degrees
extern double RAD = M_PI/180.0;
extern double ANGLEDOWN = 270.0 * RAD;
extern double ANGLERIGHT = 0;

//file
extern char* FILE_READY = "Файл успешно создан и сохранен";
extern char* READY = "Готово";
