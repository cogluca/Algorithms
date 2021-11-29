package exercise4;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;

public class Graph <T,L> {

    private HashMap<T,ArrayList<HashMap<T,T>>> entireGraph;
    private HashMap<HashMap<T,T>,L> weightsMap;
    private boolean isDirected;

    /**
     * Creazione di un grafo vuoto – O(1)
     * • Aggiunta di un nodo – O(1)
     * • Aggiunta di un arco – O(1)
     * • Verifica se il grafo è diretto – O(1)
     * • Verifica se il grafo contiene un dato nodo – O(1)
     * • Verifica se il grafo contiene un dato arco – O(1) (*)
     * • Cancellazione di un nodo – O(n)
     * - Cancellazione di un arco – O(1) (*)
     * • Determinazione del numero di nodi – O(1)
     * • Determinazione del numero di archi – O(n)
     * • Recupero dei nodi del grafo – O(n)
     * • Recupero degli archi del grafo – O(n)
     * • Recupero nodi adiacenti di un dato nodo – O(1) (*)
     * • Recupero etichetta associata a una coppia di nodi – O(1) (*)
     * @param directed
     */


    public Graph(boolean directed) {

        this.entireGraph = new HashMap<>();
        this.weightsMap = new HashMap<>();
        this.isDirected = directed;

    }

    public void addNode(T aNode) throws Exception {
        if(aNode == null)
            throw new Exception("Node doesn't exist");
        this.entireGraph.putIfAbsent(aNode, new ArrayList<HashMap<T,T>>());
    }


    public void addArc (T origin, T destination, L weight) {

        HashMap<T,T> arcIncidentFromOriginToDestination = new HashMap<>();
        arcIncidentFromOriginToDestination.put(origin,destination);

        if(this.isDirected) {
            ArrayList<HashMap<T,T>> incidentArcs = new ArrayList<>();
            incidentArcs.add(arcIncidentFromOriginToDestination);
            this.entireGraph.put(origin, incidentArcs);
            this.weightsMap.put(arcIncidentFromOriginToDestination, weight);
        }
        else {
            //creating arc
            HashMap<T,T> arcIncidentFromDestinationToOrigin = new HashMap<>();
            arcIncidentFromDestinationToOrigin.put(destination, origin);

            //adding both ways of undirected arc
            //this.entireGraph.put(origin, arcIncidentFromOriginToDestination);
            //this.entireGraph.put(destination, arcIncidentFromDestinationToOrigin);

            //adding both arc directions together with the unique weight
            this.weightsMap.put(arcIncidentFromOriginToDestination, weight);
            this.weightsMap.put(arcIncidentFromDestinationToOrigin, weight);
        }
    }

    public boolean isDirected() {
        return isDirected;
    }



    public boolean containsNode(T aNode){

       return this.entireGraph.containsKey(aNode);

    }

    public boolean containsArc(HashMap<T,T> anArc) {

        return this.entireGraph.containsValue(anArc);

    }

    public void deleteNode(T aNode) {

        HashMap<T,T> associatedArc;

        this.entireGraph.remove(aNode);



    }

    public void deleteArc(HashMap<T,T> anArc) {



    }





}
