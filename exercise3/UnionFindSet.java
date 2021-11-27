
public class Exercise1 {


    public static <T> T makeSet(T x) {

        if(x != null) {
            x.parent = x;
        }



    }


    public static <T> T unionSet(T x, T y) {
        linkSet(findSet(x), findSet(y));

    }


    public static <T> T linkSet(T x, T y) {

        if(x.rank > y.rank) {
            y.parent = x;
        }
        else(x.parent == y) {
            if(x.rank == y.rank) {
                y.rank = y.rank + 1;
            }
        }
    }

    public static <T> T findSet(T x) {
        if(x != x.parent){
            x.p = findSet(x.p)
        }
        return x.parent;
    }

}
