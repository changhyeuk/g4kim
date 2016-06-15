지안트4 싱글파일 예제

0. 알아두기
  - geant4 9.4p2 에서 작성됨
  - linux와 mac 환경에서 테스트 됨
  - 예제 파일로서 em physics builder + decay physics builder 만 포함
    hadronic interaction은 추가 builder의 import 필요
  - 환경변수 G4WORKDIR=. 으로 지정되어있어야 함(기본은 임의의 설치폴더임)

1. 실행 순서
   make
   ./bin/Linux-icc/g4single
   
2. 파일 설명
  g4single.cc : 모든 클래스를 하나의 파일 안에 정의
  src/Dummy.cc : 
  include/Dummy.hh :
    Geant4 스타일의 built-in makefile(Builder Configuration)은
    최소 한 개 이상의 소스와 헤더를 필요로 하기 때문에, 정상적 컴파일을
    위해 Dummy를 생성함
    
2011. 12. 14. garam@kirams.re.kr
