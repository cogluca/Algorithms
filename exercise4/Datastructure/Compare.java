package exercise4.Datastructure;

import java.util.Comparator;

public class Compare implements Comparator<Edge<String, Float>> {

    //Compares the labels of two edges
    @Override
    public int compare(Edge<String, Float> o1, Edge<String, Float> o2) {
        return o1.getLabel().compareTo(o2.getLabel());
    }

}
