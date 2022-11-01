import java.util.*;
import java.io.*;

class Prog_4 {
	public void inputInfile(String[] data) {

		try {
			File f = new File("./");
			FileWriter fw = new FileWriter(f.getAbsolutePath()+"/names.txt", true);
			for (int i = 0; i < data.length; i++) {
				fw.write(data[i]);
				fw.write("\n");
				;
			}
			fw.close();
		} catch (Exception e) {
			System.out.println(e);
		}

		System.out.println("\nSuccessfully Written\n");
	}

	public static void main(String[] args) {
		String[] names = new String[5];
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			System.out.println("Enter name: ");
			names[i] = sc.next();
		}

		Prog_4 obj = new Prog_4();
		obj.inputInfile(names);

		System.out.println("\nReading\n");
		File fi = new File("./");
		FileReader fr = null;
		try {
			fr = new FileReader(fi.getAbsolutePath() + "/names.txt");
		} catch (FileNotFoundException e) {
			System.out.println("File Not found");
		}
		BufferedReader bf = new BufferedReader(fr);
		try {
			String name = null;
			while ((name = bf.readLine()) != null) {
				System.out.println(name);
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}