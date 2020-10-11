
public class Specialization {
    int ID;
    String uniName;

    public int getID() {
        return ID;
    }

    public String getUniName() {
        return uniName;
    }

    public Specialization(int ID, String uniName) {
        this.ID = ID;
        this.uniName = uniName;
    }

    @Override
    public int hashCode() {
        return ID;
    }

    @Override
    public String toString() {
        return "{ "+ID+" : "+ uniName +"} ";
    }
}
