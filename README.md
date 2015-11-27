# convex-hull


######point-set-generator:

      SYNOPSIS:
            point-set-generator [POINTS] [RANGE] [OPTIONS]

      DESCRIPTION:
            A utility to generate a set of random 2D cartesian coordinates. Outputs to stdout.
            
            POINTS specifies the number of points to generate.
            RANGE specifies the absolute value of the maximum and minimum values of the coordinates.
          
                  Options:

                        -s
                              generates points sorted in nondecreasing order of their x coordinates
                              with ties resolved by increasing order of the y coordinates of the 
                              points involved.
            
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
            
            
####Usage Examples:

##### finding convex set and displaying only processing time:
~/convex-hull/src$ ./point-set-generator 20 20 | ./brute-force

Output:
> Cycles: 168

##### finding convex set and graphing the result:
~/convex-hull/src$ ./point-set-generator 20 20 | ./brute-force -g | ./grapher 25
      
Output: 
> [Resulting Graph](https://raw.githubusercontent.com/27tang/convex-hull/master/src/sampleOutput.out)
