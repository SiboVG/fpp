module FppTest {

  module SmJunction {

    @ A basic state machine with a junction
    state machine Basic {

      @ Action a
      action a

      @ Action b
      action b

      @ Signal s
      signal s

      @ Guard g
      guard g

      @ Initial transition
      initial enter S1

      @ State S1
      state S1 {

        @ State transition
        on s enter J

      }

      @ Junction J
      junction J {
        if g do { a } enter S2 else do { b } enter S3
      }

      @ State S2
      state S2

      @ State S3
      state S3

    }

  }

}
