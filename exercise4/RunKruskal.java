    package exercise4;

    import exercise4.datastructure.Graph;
    import exercise4.utils.DataUtils;

    import java.util.Scanner;

    public class RunKruskal {

        public static void main(String[] args) {

            Graph<String, Float> toTestGraph;
            Graph<String, Float> returnedForest;
            float distance = 0;

            String filename;
            Scanner scanner = new Scanner(System.in);

            System.out.println("Would like to know which file you're trying to load");
            filename = scanner.nextLine();

            try {
                toTestGraph = DataUtils.loadGraph(DataUtils.loadData(filename));
                returnedForest = Kruskal.tryKruskal(toTestGraph);
                distance = DataUtils.getTotalForestDistance(returnedForest);

                System.out.println("Total distance in this minimal forest is: " + distance/1000);
                System.out.println("Total number of edges in this forest is: " + returnedForest.graphEdgeSize());
                System.out.println("Total number of nodes in this forest is: " + returnedForest.graphNodeSize());

            } catch (Exception ex) {
                System.out.println(ex.getMessage());
                System.out.println("Something went wrong during file loading and unpacking");
            }


        }

    }



