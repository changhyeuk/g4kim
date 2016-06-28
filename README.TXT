The Code was modifed from the g4single.cc

  - The code is slightly different with conventional geant4 code. 
  - The AnalysisManager.cc and Analysis code, which was written based on ROOT, were introduced. 
  
For the detailed analaysis, you should following 

  in terminal 
  
  - root PostChang.C case.root
  
  it will be generate two files
  
  - case_analysis.root and case_analysis.txt
  
  the txt file should be corrected in near future.
  
  the case_analysis_root file can be show the simulation results by 
  
  - root
  - root[0] TBrowser TB;
    and, you can just using the tree of directory
    
