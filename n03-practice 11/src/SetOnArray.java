import java.util.*;

public class SetOnArray <E>{

    private ArrayList[] array;

    public ArrayList[] getArray() {
        return array;
    }

    private int capacity;


    public SetOnArray(int capacity) {
        this.capacity = capacity;
        array = new ArrayList[capacity];
        for (int i = 0; i < capacity; i++)
            array[i] = new ArrayList();
    }


    public boolean add(E e) {

        int hCode = e.hashCode() % capacity;
        if (array[hCode].contains(e))
            return false;
        else {
            array[hCode].add(e);
            return true;
        }
    }


    public void clear() {
        for (ArrayList<? extends Object> ai : array)
            ai.clear();
    }

    public boolean contains(E e) {
        int hCode = e.hashCode() % capacity;
        return array[hCode].contains(e);

    }

    public boolean remove(E e) {
        int hCode = e.hashCode() % capacity;
        if (!array[hCode].contains(e))
            return false;
        else {
            array[hCode].remove(e);
            return true;
        }
    }


    public String toString() {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < capacity; i++) {
            res.append(i + ":" + array[i].toString() + "\n");
        }
        return res.toString();
    }
}
