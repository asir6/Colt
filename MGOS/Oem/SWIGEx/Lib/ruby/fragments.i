// Helper function for Array output

%fragment("output_helper", "header") %{
static VALUE output_helper(VALUE target, VALUE o) {
    if (NIL_P(target)) {
	target = o;
    } else {
	if (TYPE(target) != T_ARRAY) {
	    VALUE o2 = target;
	    target = rb_ary_new();
	    rb_ary_push(target, o2);
	}
	rb_ary_push(target, o);
    }
    return target;
}
%}
