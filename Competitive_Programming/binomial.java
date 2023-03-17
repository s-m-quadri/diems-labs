class Main {
  static int binomial(int p, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
      int factor = 1;
      for (int j = 1; j <= i; j++) {
        factor = factor * (p - (j - 1)) / j;
      }
      System.out.println(factor);
      if (factor == 0) break;
      result = result + factor;
    }
    return result;
  }

  public static void main(String args[]) {
    System.out.println(binomial(2, 100));
  }
}