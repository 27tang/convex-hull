# convex-hull


######point-set-generator:

      SYNOPSIS:
            point-set-generator [POINT COUNT] [RANGE]

      DESCRIPTION:
            A utility to generate a set of random 2D cartesian coordinates. Outputs to stdout.
            
            POINT COUNT specifies the number of points to generate.
            RANGE specifies the absolute value of the maximum and minimum values of the coordinates.
      
            
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
            grapher [GRAPH SIZE] [OPTION]
      
      DESCRIPTION:
            A graphing utility that takes the result of a convex-hull calculation
            from stdin and plots them on a cartesian graph. X's mark points in the convex set
            and O's mark points that are not.
            
            The coordinates of each point is shown to the left of the graph. Points belonging
            to the convex set are surrounded by [ ].
            
            The GRAPH SIZE argument specifies maximum x/y value of the graph.
            
            Options:
                  -s
                        disables coordinate printing
            
            
####Usage Example: 
      ~/convex-hull-project/src$ ./point-set-generator 20 20 | ./brute-force | ./grapher 25
######[--------->output](https://raw.githubusercontent.com/27tang/convex-hull/master/src/sampleOutput.out)
