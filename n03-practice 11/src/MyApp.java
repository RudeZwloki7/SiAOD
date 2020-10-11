import java.util.ArrayList;
import java.util.Scanner;

public class MyApp {
    public static void main(String[] args) {
        Specialization test = new Specialization(111111,"UNIVERSITY");
        SetOnArray<Specialization> set = new SetOnArray<>(10);
        for (int i = 0;  i<30; i++ ){
            Specialization temp = new Specialization ((int) (Math.random()*1000000),"University_"+i);
            set.add(temp);

        }
        set.add(test);
        System.out.println(set.toString());
        System.out.println(set.contains(test));
        set.remove(test);
        System.out.println(set.toString());
        System.out.println(set.contains(test));
        set.clear();
        System.out.println(set.toString());



    }


}
