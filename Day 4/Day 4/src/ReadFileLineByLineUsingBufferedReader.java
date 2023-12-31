import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.lang.Math;

public class ReadFileLineByLineUsingBufferedReader {

    public static void main(String[] args) {
        BufferedReader reader;


        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            String line = reader.readLine();
            int comptTot = 0;
            Integer[] listOfCopies = new Integer[202];
            Arrays.fill(listOfCopies,1);
            int numberOfLine = 0;
            boolean Continue = true;
            while (line != null && Continue) {


                int compt = 0;
                String[] lineSplited = line.split(":");
                //System.out.println(lineSplited[1]);
                boolean testPassed = false;
                List<Integer> firstList = new ArrayList<>();
                List<Integer> secondList = new ArrayList<>();
                for (int i = 1; i < lineSplited[1].length(); i= i + 3) {
                    if (lineSplited[1].charAt(i) == '|')  {
                        i = i + 2;
                        testPassed = true;
                    }
                    int decalage = 0;
                    //System.out.println(lineSplited[1].charAt(i+1));
                    if (lineSplited[1].charAt(i) == ' ') {
                        decalage = 1;
                    }
                    if (testPassed) {
                        firstList.add(Integer.parseInt(lineSplited[1].substring(i+decalage,i+2)));
                    }
                    else {
                        secondList.add(Integer.parseInt(lineSplited[1].substring(i+decalage,i+2)));
                    }
                }
                for (Integer value : secondList) {
                    for (Integer integer : firstList) {
                        if (value == integer) {
                            //System.out.println("Ligne N°" + numberOfLine + ", same value : " + value);
                            compt++;
                        }
                    }
                }
                //System.out.println("Compt : " + compt);
                if (compt > 0) {
                    /*
                    System.out.println();
                    System.out.println("Number of lines : " + numberOfLine);
                    System.out.println("Compt : " + compt);
                    */
                    for (int i = numberOfLine; i < compt+numberOfLine; i++) {
                        listOfCopies[i+1] = listOfCopies[i+1] + listOfCopies[numberOfLine];
                    }
                }

                //System.out.print("List of copies : ");
                //for (Integer number : listOfCopies) System.out.print(number + " ");
                if (compt == 0 && listOfCopies[numberOfLine] == 1) {
                    int i = 0;
                    System.out.println("Yolo");
                    System.out.print("List of copies : ");
                    for (Integer number : listOfCopies) System.out.print(number + " ");
                    System.out.println();
                    System.out.println(listOfCopies[i] > 1);
                    while (listOfCopies[i] > 1 || i == 0) {
                        System.out.println("Bouclage");
                        System.out.print("List of copies : ");
                        for (Integer number : listOfCopies) System.out.print(number + " ");
                        comptTot += listOfCopies[i++];
                    }
                    System.out.println();
                    System.out.println("ComptTot : " + (comptTot+1));
                    Continue = false;
                }
                // read next line
                line = reader.readLine();
                numberOfLine++;

            }
            for (Integer number: listOfCopies) comptTot += number;
            System.out.println(Arrays.toString(listOfCopies));
            System.out.println("ComptTot : " + (comptTot));

            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}