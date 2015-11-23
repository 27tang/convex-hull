# convex-hull-project


######point-set-generator:
      creates a set of random points and outputs to stdout
          usage:
                  point-set-generator [number of points desired] [output range]
            
######brute-force:
      takes set of points from stdin and outputs a set of lines (edges of the convex-hull) -- uses the      
      brute-force algorithm.
          usage:
                  brute-force < [input file]
      
######quick-hull:
      takes set of points from stdin and outputs a set of lines (edges of the convex-hull) -- uses the      
      quickhull algorithm.
          usage:
                  quick-hull < [input file]
                  
######grapher:
      takes result of a convex-hull calculator from stdin and plots them on a cartesian 
      graph
            usage: grapher [range/size of graph]
            
####Usage Example:
      ~/convex-hull-project/src$ ./point-set-generator 20 20 | ./brute-force | ./grapher 25
      
