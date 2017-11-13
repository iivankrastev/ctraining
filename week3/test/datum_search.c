int queue_search (void *_ctx,
		  queue_datum_type dtype,
		  queue_datum *d){
    
    while (queue_get(_ctx, d)){

	if (d->type == dtype){
	    printf("Type found\n");
	    return 1; 
	}
    }
    
    printf("type not found\n");
    return 0;
}
