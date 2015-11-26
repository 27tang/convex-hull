# convex-hull


######point-set-generator:
      creates a set of random points and outputs to stdout
          usage:
                  point-set-generator [number of points desired] [output range]
            
######brute-force:

      SYNOPSIS:
            brute-force [OPTION]
      
      DESCRIPTION:
            takes set of points from stdin and calculates the convex set using a brute-force
            algorithm. Outputs the processing time (number of cycles) by default.
                  Options:
                        -g 
                              outputs the original set of points and the convex set in a format
                              that can be used as input for the grapher utility.

      
######quick-hull:

      SYNOPSIS:
            quick-hull [OPTION]
      
      DESCRIPTION:
            takes set of points from stdin and calculates the convex set using quickhull
            algorithm. Outputs the processing time (number of cycles) by default.
                  Options:
                        -g 
                              outputs the original set of points and the convex set in a format
                              that can be used as input for the grapher utility.
                  
######grapher:

      SYNOPSIS: 
            
      takes result of a convex-hull calculator from stdin and plots them on a cartesian 
      graph
            usage: grapher [range/size of graph]
            
####Usage Example: 
      ~/convex-hull-project/src$ ./point-set-generator 20 20 | ./brute-force | ./grapher 25
######[--------->output](https://raw.githubusercontent.com/27tang/convex-hull/master/src/sampleOutput.out)
