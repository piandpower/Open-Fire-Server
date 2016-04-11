<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateStrongpointEdgesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('strong_point_edges', function (Blueprint $table) {
            $table->increments('id');
            $table->integer('start_strong_point_id')->unsigned();
            $table->foreign('start_strong_point_id')->references('id')->on('strong_points');
            $table->integer('end_strong_point_id')->unsigned();
            $table->foreign('end_strong_point_id')->references('id')->on('strong_points');
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::drop('strong_point_edges');
    }
}
