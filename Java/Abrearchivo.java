import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Abrearchivo {
	//El siguiente proceso muestra el contenido y manda error si no se encuentra el archivo
	public static void muestraContenido(String archivo) throws FileNotFoundException, IOException{
		String cadena;
		FileReader f new FileReader(archivo);//Se crea una variable de tipo FileReader para abrir el archivo
		BufferedReader b = new BufferedReader(f);
		while((cadena = b.readLine())!=null){//Se lee el archivo linea a linea hasta que no tenga contenido
			System.out.println(cadena);
		}
		b.close();
	}
	
	public static void main(String []args) throws IOException{
		muestraContenido("D:/Algoritmos y estructuras de datos/Codigo(Librerias)/Java/Archivo.txt");
	}
	//NOTA: Las rutas se marcan usando el guion convencional: "/"
}