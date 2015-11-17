# convex-hull-project

-Various convex-hull algorithm implementations-



######point-set-generator:
      creates a file with a set of random points
          usage:
                  point-set-generator [number of points desired] [name of output file]
      
######brute-force:
      takes set of points from std-in and outputs a set of lines (edges of the convex-hull) -- uses the      
      brute-force algorithm.
          usage:
                  brute-force < [name of input file]
      
######quick-hull:
      takes set of points from std-in and outputs a set of lines (edges of the convex-hull) -- uses the      
      quickhull algorithm.
          usage:
                  quick-hull < [name of input file]
      
