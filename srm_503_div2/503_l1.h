
class ToastXRaspberry
{
 public:
  int apply(int upper_limit, int layer_count)
  {
    return (layer_count + upper_limit - 1) / layer_count;
  }
};

